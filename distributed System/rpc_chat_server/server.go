/*rpc server listen to register new members to the chat and if client is already member then send unread msgs to him
 *if member send message broadcast it to other clients who are online and write it int to the unread messages log
  to clients who are offline
**/
package main
import (
	"fmt"
	"log"
	"net"
	"net/rpc"
	//"reflect"
	//"bufio"
	//"os"
	"container/list"
)	

type Message struct {
    ClientIp string
    Msg      string
}
type ClientInfo struct {
    Hostname, Ip_port string
}

var MembersName map[string]string       //(ip, username)
var ConnStates	map[string]bool 		//(client, online)
var onlineClnts	map[string]*rpc.Client 	//(onclient, rpcclientsocket)
var ClientsLog  map[string]*list.List 	//(client, unread messages)
type Listener   int

//create rpc client connect to rpc server
func CreateRpcClient(clientAddr string)*rpc.Client{
	rpcClient, err := rpc.Dial("tcp", clientAddr)
	if err != nil {
		log.Fatal("server is shutdown")
	}
	return rpcClient
}

//send unread messages to client when he/she log in the chat
func (l *Listener) SndUnrdMesgs(client string, messages *string) error {
	fmt.Println("*send unread msgs to ", client,"  ")
	
	if _, ok := ClientsLog[client]; ok{
		unreadMsgs := ClientsLog[client]
		msg := unreadMsgs.Front()

		for ; msg != nil; {
			*messages = *messages + msg.Value.(string) + "\n"
			//err := onlineClnts[client].Call("Listener.OthersMsg", msg.Value, &ack)
			unreadMsgs.Remove(msg)
			msg = unreadMsgs.Front()
		}
	}
	return nil
}

/*Register the client into the chat by his ip and hostname 
  we can make that by password and username*/
func (l *Listener) Registeration(clientInfo *ClientInfo, ack *bool) error {
	ipPort := clientInfo.Ip_port
	MembersName[ipPort] = clientInfo.Hostname
	//create rpc client connect to rpc server 
	rpcClient, err := rpc.Dial("tcp", ipPort)

	//check if this client new to the chat or not
	if _, ok := ConnStates[ipPort]; !ok{
		NotifyClients(ipPort, " is new member")
		if err == nil {
			//change connection state of this client
			fmt.Println("add ", ipPort, "as new member")
			ConnStates[ipPort] = true
			onlineClnts[ipPort] = rpcClient
		}else{
			ConnStates[ipPort] = false
		}	
	}else{
		fmt.Println(ipPort, " is already member")
		//send unread messages
		if err == nil {
			NotifyClients(ipPort, " is online now")
			ConnStates[ipPort] = true
			onlineClnts[ipPort] = rpcClient
		}
	}
	return nil
}

/*tell the client who are offline and online members 
   when he log in the chat*/
func (l *Listener) ChatMembers(host string, members *string) error {
	online  := "Online Members : "
	offline := "Offline Members : "
	
	for member, _ := range ConnStates{
		if member != host{
			if ConnStates[member]{
			online += MembersName[member]+"  "
			}else{
				offline += MembersName[member]+"  "
			}
		}
	}
	*members = online + "\n" + offline
	return nil
}

//write message into client unread messages log
func WriteLog(client, msg string){
	fmt.Println("write it to", client," its log")
	if _, ok := ClientsLog[client]; !ok{
		ClientsLog[client] = list.New()
		ClientsLog[client].PushBack(msg)
	}else{
		ClientsLog[client].PushBack(msg)
	}
}

//notify clients if any member becomes offline or online
func NotifyClients(host, message string){ 
	var ack bool
	offs := list.New()
	ms  := "*server : " + MembersName[host] + message

	//tell online clients the status of a member
	for member, _ := range onlineClnts{
		if member != host{
			err := onlineClnts[member].Call("Listener.OthersMsg", ms, &ack)
			if err != nil{
			//this member is off now
				offs.PushBack(member)
			}
		} 
	}
}

//Broad cast the message to all clients except the sender
func (l *Listener) BroadCast(msg Message, ack *bool) error {
	fmt.Println("*", msg.ClientIp, "BroadCast msg")
	
	for ipPort, _ := range ConnStates{
		if ConnStates[ipPort] {
		//if client is online
			if ipPort != msg.ClientIp {
				err := onlineClnts[ipPort].Call("Listener.OthersMsg", msg.Msg, ack)

				if err != nil {
					fmt.Print("*", ipPort, " not receive the msg ")
					//remove him from the online clients
					delete(onlineClnts, ipPort)
					ConnStates[ipPort] = false
					WriteLog(ipPort, msg.Msg)
					//NotifyClients(ipPort, " is offline now")
				}else{fmt.Println("*", ipPort, " receive the msg")}
			}
		}else{
		//if client is offline
			WriteLog(ipPort, msg.Msg)
		}
	}
	return nil
}

//this function create tcpListener on specific port
func StartListening()(*net.TCPListener){
	//addy, err := net.ResolveTCPAddr("tcp", "192.168.1.7:42586")
	addy, err := net.ResolveTCPAddr("tcp", "127.0.0.1:42586")

	if err != nil {
		log.Fatal(err)
	}

	tcplistenr, err := net.ListenTCP("tcp", addy)
	if err != nil {
		log.Fatal(err)
	}
	return tcplistenr
}

//check connection state of every client in periodic time
func IsLive(){
	for{
	for member, _ := range onlineClnts{
		_, err := net.Dial("tcp", member)

		if err != nil {
			//fmt.Println(member, "is ofline")
			delete(onlineClnts, member)
			ConnStates[member] = false
    		NotifyClients(member, " is offline now")
		}
	}
}
}


func main() {
	//create map of clients
	MembersName = make(map[string]string)
	ConnStates  = make(map[string]bool)
	onlineClnts	= make(map[string]*rpc.Client)
	ClientsLog  = make(map[string]*list.List)
	tcplistenr  := StartListening()

	//register listening service
	listener := new(Listener)
	rpc.Register(listener)

	//wait messages
	go IsLive()
	rpc.Accept(tcplistenr)
	
}