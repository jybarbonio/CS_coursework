'''
from socket import *
serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Input lowercase sentence:')
clientSocket.sendto(message.encode(),(serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print (modifiedMessage.decode())
clientSocket.close()

'''

from socket import *
import re
import uuid
import time

# DISCOVER      = 0
# OFFER         = 1
# REQUEST       = 2
# ACKNOWLEDGE   = 3
# send mac to server
def discover():
    msgmac = (':'.join(re.findall('..', '%012x' % uuid.getnode())))

    code = "[0] "
    msgmac = code + msgmac
    print("CLIENT: mac addr ", msgmac)

    clientSocket.sendto(msgmac.encode(), (serverName, serverPort))
    msgReturn, AssignedIP = clientSocket.recvfrom(2048)
    msgReturn = msgReturn.decode()
    print("CLIENT: returned ", msgReturn)

if __name__ == '__main__':
    serverName = 'localhost'
    serverPort = 15001
    clientSocket = socket(AF_INET, SOCK_DGRAM)


    discover()

    clientSocket.close()
