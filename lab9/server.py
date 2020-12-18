# Using TCP/IP sockets, write a client-server program to make client sending
# the file name and the server to send back the contents of the requested file if
# present.

from socket import *

serverName="127.0.0.1"
serverPort = 12000

serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print ("The server is ready to receive")
while 1:
    connectionSocket, addr = serverSocket.accept()
    sentence = connectionSocket.recv(1024).decode() 
    file=open(sentence,"r")
    l=file.read(1024) 
    connectionSocket.send(l.encode())
    file.close()
    connectionSocket.close()