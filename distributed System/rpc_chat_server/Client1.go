/*Client listen to the os.stdin file descriptor then send the message to the server where server will 
  broadcast it to other live clients
 *client machine run as rpc client where use broadcast service in rpc server
 *client machine run as rpc server where the chat server use otherMsg service in the client
 *when client registers at the rpc server he/she knows who are on the chat
 *If he/she already chat member he gets unread messages when connect to the rpc server
**/
package main

import (
	//"bufio"
	"log"
	"net/rpc"
	"os"
	"fmt"
	"net"
	"strings"
	"time"
	//"container/list"
)
var rpcClient *rpc.Client
var clientInfo   ClientInfo
type Listener   int 
type ClientInfo struct {
    Hostname, Ip_port string
}
type Message struct {
    ClientIp string
    Msg      string
}


func FormatMsg(msg string) string{
	tt   := time.Now().Format("Sat Jan _2 2006 15:04:05 ")
	host := "("+ clientInfo.Hostname + ") : "
	head := host + tt + "\n*****************\n"
	msg = head + msg
	return msg
}

func (l *Listener) OthersMsg(msg string, ack *bool) error {
	if msg[len(msg)-1] != '~'{
		fmt.Println(msg)
		fmt.Println("_____________________")
	}else{
		var  reply bool
		ms := FormatMsg(msg[:len(msg)-1])
		fmt.Println(ms)
		fmt.Println("^^^^^^^^^^^^^^^^^^^^^")
		err := rpcClient.Call("Listener.BroadCast", Message{clientInfo.Ip_port, ms} , &reply)
		if err != nil {
			log.Fatal("server is shutdown")
		}
	}
	return nil
}

/*this function get the Ip address of machine in network
	to register in the rpc server with it
*/
func GetIp() (string){
	//make connectionless communication to any ip 
	conn, err := net.Dial("udp", "192.4.8.8:80")
	defer conn.Close()
   if err != nil{
        fmt.Println("Error During read Interfaces")
        os.Exit(1)
    }
    //get local ip addr from this connectionless handler
    localAddr := conn.LocalAddr().(*net.UDPAddr).String() 
    i := strings.Index(localAddr,":")
    
    return localAddr[:i] 
}

//this function get host name of the current machine
func HostName()string{
	var err error
	hostname, err := os.Hostname()
	if err != nil {
		log.Fatal(err)
	}
	return hostname
}

//get the ip address of the rpc server from input args
func GetIpServer() string{
	if len(os.Args) != 2{
		log.Fatal("pass only ipaddress of the server")
	}
	return os.Args[1]
}

func RpcServConnection(serverip string) {
	//Get Client Information
	port   := "5550"
	//ip   := GetIp()
	ip     := "localhost"
	clientInfo.Ip_port  = ip + ":" + port
	clientInfo.Hostname = "ahmed saad" //HostName()

	//create rpc client connect to rpc server
	var err error
	rpcClient, err = rpc.Dial("tcp", serverip)
	if err != nil {
		log.Fatal("server is shutdown")
	}
}

func ChatMembers(host string){
	var members  string
	err := rpcClient.Call("Listener.ChatMembers", host , &members)
	if err != nil {
		log.Fatal("can't connect to the server")
	}
	fmt.Println(members)
	fmt.Println("_____________________")
}

func UnReadMsgs(host string){
	var messages  string
	err := rpcClient.Call("Listener.SndUnrdMesgs", host , &messages)
	if err != nil {
		log.Fatal("can't connect to the server")
	}
	fmt.Println(messages)
}

//this function wait message from client to broadcast it
func MyMsg(){
	//who are chat members ?
	ChatMembers(clientInfo.Ip_port) 
	// are there unread msgs?
	UnReadMsgs(clientInfo.Ip_port)
	//register to the rpc server
	var reply bool
	err := rpcClient.Call("Listener.Registeration", &clientInfo, &reply)
	if err != nil {
			log.Fatal("can not register at the server")
	}	
}

//this function create tcpListener on specific port
func StartListening()(*net.TCPListener){
	addy, err := net.ResolveTCPAddr("tcp", clientInfo.Ip_port)

	if err != nil {
		log.Fatal(err)
	}

	tcplistenr, err := net.ListenTCP("tcp", addy)
	if err != nil {
		log.Fatal(err)
	}
	return tcplistenr
}
/*
func StillLive(){
	ln, err := net.Listen("tcp", "localhost:5550")
	if err != nil {	}
	for {
		_, err := ln.Accept()
		if err != nil {}
	}
}*/

func main() {
	
	ipServer := GetIpServer()
	RpcServConnection(ipServer)

    tcplistenr := StartListening()

	//register listening service
	listener := new(Listener)
	rpc.Register(listener)

	//wait messages
	MyMsg()
	rpc.Accept(tcplistenr)
}