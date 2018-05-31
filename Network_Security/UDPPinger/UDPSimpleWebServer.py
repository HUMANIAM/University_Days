"""
Author  : Ibrahim Elsaid Saad
program : I create it to only test the udppinger
"""

import time
import socket
def main():
	server_address = ('', 10000)
    #create new socket using connectionless protocol UDP type
	listen_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	#bind socket to server_address
	listen_socket.bind(server_address)
	
	while True:
			#wait data from client
			request, addr= listen_socket.recvfrom(1024)
			http_response = b"""HTTP/1.1 200 OK \n\n Yes I am?"""
			#send arbitrary response
			listen_socket.sendto(http_response, addr)
	listen_socket.close()   	
    
if __name__ == '__main__':
	main()