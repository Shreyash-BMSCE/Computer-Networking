# Using TCP/IP sockets, write a client-server program to make client sending
# the file name and the server to send back the contents of the requested file if
# present.

from socket import *

serverName = "127.0.0.1"
serverPort = 12000

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

sentence = input("Enter file name: \n")
clientSocket.send(sentence.encode())
filecontents = clientSocket.recv(1024).decode()
print ('From Server:', filecontents)

clientSocket.close()