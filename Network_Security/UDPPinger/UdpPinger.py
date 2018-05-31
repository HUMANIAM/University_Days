"""
Author  : Ibrahim Elsaid Saad
Program : This program ping the local udp webserver and 
          waits the response with timeout = 1 . pinging 
          occurs with 10 packets to the server
"""
import socket
import sys
import os
import time

def StartBinging(Ip, port):
	#create socket of type UDP and family ip4
	mysock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	#set timeout to receive response from the server
	mysock.settimeout(1.0)
	#address server that we will ping 
	hostserver = (Ip, int(port))
	#sending message to the server
	message = b"GET / HTTP/1.1\r\n\r\n are you there?"
	Recieved , Loss = 0, 0
	#send ten packages to the host server
	for times in range(1,11):
		#send request message
		try:
			#UDP is connectionless protocol no reliable transfer
			mysock.sendto(message, hostserver)
			startTime = time.clock()
		except socket.error:
			print('sent failed')
			sys.exit(1)

		#wait the response message
		try:
			response = ''
			response, addr = mysock.recvfrom(1024) 
			print('RTT = ', format((time.clock() - startTime), '.4g'))
			Recieved = Recieved + 1
			pass
		except ConnectionResetError  | socket.timeout :
			Loss = Loss + 1
			print('RTT>1sec')
			pass

	#ping statistics
	print('Ping statics:\n________________ ')
	print('sent messages = 10',' Lost messages =', Loss,
		'Recieved messages =', Recieved)
	mysock.close()

def main():
	if len(sys.argv) == 2:
		try:
			hostIp = ''
			domain_name = sys.argv[1]
			hostIp_port = domain_name.split(':')
			hostIp = socket.gethostbyname(hostIp_port[0])
		except:
			print('server host name isn\'t right')

		try:
			print('pining {} [{}] with 16 bytes of data'
				.format(domain_name.split()[0], hostIp))
			StartBinging(hostIp, int(hostIp_port[1]))
		except:
			print('an Error occures during ping check domain name\n')
	else:
		print('You need to pass the program name and' 
			  ' server host name to python interpreter')

if __name__ == '__main__':
	main()