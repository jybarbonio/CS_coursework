from socket import *

if __name__ == '__main__':
    serverPort = 15001
    serverSocket = socket(AF_INET, SOCK_DGRAM)

    lstIPs = [['192.168.45.' + str(i + 1), False, None, None] for i in range(14)]

    # load connection into IP vector/list
    # list format: assigned client IP / assigned bool / client MAC addr / timeout 60 sec
    for i in lstIPs:
        if(i[2] == serverSocket.recvfrom):
        serverSocket.bind(('', serverPort))
    
    
    print ('The server is ready to receive')
    while 1:
        message, clientAddress = serverSocket.recvfrom(2048)
        modifiedMessage = message.decode().upper()
        serverSocket.sendto(modifiedMessage.encode(), clientAddress)
