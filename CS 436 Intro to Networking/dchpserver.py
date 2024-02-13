'''
from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print ('The server is ready to receive')
while 1:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.decode().upper()

'''

from socket import *
import numpy as np
import time
import re

def offer(code, mac):
    nextEmpty = 0
    print("SERVER: ", code, mac)
    # case A: checks if the mac addr and ip a/lready exists in vector
    for i, m in enumerate(lstIPs):
        # case B: if record was found, check timestamp
        if(m[2] == mac):
            # case B2: if not expired then server sends back ACKNOWLEDGE code
            if(time.time() - m[3] < 60.0):
                msgExists = str("[3]" + " " + mac + " " + str(time.time() - m[3]))
                # needs tuple of serverName and serverPort for second param
                serverSocket.sendto(msgExists.encode(), clientAddress)
                print(i, m)
                return
            # case C: re-offer if expired
            else:
                m[3] = time.time() + 60.0 # update
                msgExpired = str("[1]" + " " + mac + " " + m[0] + " " + m[3])
                serverSocket.sendto(msgExpired.encode(), clientAddress)
                print(i, m)
                return
        else:
            if(m[2] == None):
                nextEmpty = i
    '''
    for i, s in enumerate(lstIPs):
        if(lstIPs[i][1] == False):
            print("assigning to empty slot")
            lstIPs[i][1] = True
            lstIPs[i][2] = mac
            lstIPs[i][3] = time.time()
            print("assigned lst slot is now")
            print(lstIPs[i])

            msgOffer = str("[1]" + " " + str(mac) + " " + str(lstIPs[i][0]) + " " + str(lstIPs[i][3]))
            serverSocket.sendto(msgOffer.encode(), clientAddress)
            return
        else:
            print(lstIPs[i], "is already assigned")
            # elapsed time timeout after one minute
            if(time.time() - lstIPs[i][3] > 60):
                print("timing out")
                # print(lstIPs[i])
    '''
    


if __name__ == '__main__':
    serverPort = 15001
    serverSocket = socket(AF_INET, SOCK_DGRAM)
    serverSocket.bind(('', serverPort))
    # serverSocket.bind(('', serverPort))

    # 2D vector with 1 - 14 IP range
    # assigned client IP / assigned bool / client MAC addr / timeout 60 sec
    lstIPs = [['192.168.45.' + str(i + 1), False, None, None] for i in range(14)]

    print ('The server is ready to receive')
    while 1:
        # get msg but ignore clientAddress autoassign
        msg, clientAddress = serverSocket.recvfrom(2048)
        msg = msg.decode()

        m = re.compile('\[\d\]')
        code = m.search(msg)
        msgtrunc = msg.replace(code.group(), '')
        
        # if client sends DISCOVER
        if(code.group() == '[0]'):
            offer(code.group(), msgtrunc)
        # elif client sends REQUEST
        elif(code.group() == "[2]"):
            pass

    # commented out - always listen for client!
    # serverSocket.close()