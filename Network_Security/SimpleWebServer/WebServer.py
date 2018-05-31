#import the socket package
import socket
import os
import time

"""
TCP guarantees connection_oriented , reliable transfer
and congestion flow
"""
class WebServer(object):
	def __init__(self):
		#create socket with Tcp connection
		self.mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		#server address
		serverAddress = ('', 8088)
		try:
			#bind mysock with serverAddress
			self.mysock.bind(serverAddress)
		except:
			print("Address already in use")
			exit(1)
		#is how many connections the OS may accept on behalf of the application. 
		self.mysock.listen(3)
		pass
		
	def StartSevices(self):
		#waits requests from clients
		while True:
			#accept connection with the client
			(clientSocket, addr) = self.mysock.accept()
			print ("hello") 
			#get request packet data 
			request = clientSocket.recv(1024).decode()
			#send response
			response = self.GetResponse(request)
			clientSocket.sendall(response.encode())
			# Close the connection
			clientSocket.close()
		#close the server socket
		self.mysock.close()               
		pass
	
	
	def GetHeader(self, statusCode, length = 0, filepath = ''):
		print(statusCode)
		if(statusCode == 200):
			header = "HTTP/1.1 200 OK\n"
		else:
			header = 'HTTP/1.1 404 Not Found\n'
		#server
		header += 'Server : SimpleTcpServer\n\n'
		#date and time
		header += ("Date : " + time.strftime("%c") + "\n")  
		if(statusCode == 200):
			#content_type
			extension = os.path.splitext(filepath)[1]
			header += "Content_Type : " + str(extension) + "\n"
			#content_length
			header += "Content_Length  : " + str(length) + "\n"
		#connection
		header += 'Connection : Close\n\n'

		return header
	pass
		
		
	def GetResponse(self, request):
		#split it to get the desired path
		if(request):
			request_parts = request.split()
			filepath = request_parts[1][1:]  
		else: 
			return ''
			
		#open the file and get data then send it to the client
		try:
			fhandle = open(filepath)
			responsData = fhandle.read()
			header = self.GetHeader(200, len(responsData), filepath)
			responsData =  header + responsData
			return responsData
		except:
			#file isn't found
			return self.GetHeader(404)	
	pass


def main():
	webserver = WebServer()
	webserver.StartSevices()
	
if __name__=="__main__":
	main()
