package main

import (
	//"container/list"
	"log"
	"net/rpc"
	"fmt"
	"bufio"
	"net"
	"strings"
	"os"
)

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

func CreateRpcClient(clientAddr string)*rpc.Client{
	rpcClient, err := rpc.Dial("tcp", clientAddr)
	if err != nil {
		log.Fatal("your chat program isn't running or rerunnig")
	}
	return rpcClient
}

//this function get host name of the current machine

func main() {
	//ipPort := GetIp() + ":5550"
	ipPort := "localhost" + ":5550"
	rpcClient := CreateRpcClient(ipPort)

	//wait for a message from the user
	in := bufio.NewReader(os.Stdin)
	for {
		 msg, _, err := in.ReadLine()
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("^^^^^^^^^^^^^^^^^^^^^")
		var reply bool
		err = rpcClient.Call("Listener.OthersMsg", string(msg)+"~" , &reply)
		if err != nil {
			log.Fatal("your chat program isn't running")
		}
	}
}