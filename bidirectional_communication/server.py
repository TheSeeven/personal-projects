import threading
import sys
import socket
import signal

IP = int(sys.argv(1))
PORT = sys.argv(2)


INCOMING = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
INCOMING.bind(("<broadcast>",PORT))

connections = []

class Bidirectional:
    def __init__(self,IP,PORT,MESSAGE):
        self.IP = IP
        self.PORT = PORT
        self.MESSAGE = MESSAGE

    def execute(self):
        OUTGOING = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        OUTGOING.sendto(bytes(self.MESSAGE),(self.IP,self.PORT))

def get_port(string):
    PORT = ""
    for i in string:
        if i == ':':
            break
        else:
            PORT += i
    return int(PORT)        

def accept_connection(): # Thread
    global connections
    while True:
        MESSAGE = INCOMING.recvfrom(50)
        CON = Bidirectional(MESSAGE[1][1],get_port(bytes(MESSAGE[0],"utf-8")),bytes(MESSAGE[0],"utf-8"))
        connections.append(CON)
        print(CON[1][1],":",get_port(bytes(MESSAGE[0],"utf-8")))


def comunicate(): # Thread
    global connections
    while True:
        for i in connections:
            i.execute()
            print("The message was sent to:",i.IP,":",i.PORT,":-",i.MESSAGE)
            del i


def exit_program(): # Thread
    while True:
        try:
            pass
        except KeyboardInterrupt:
            sys.exit()

t1 = threading.Thread(target=accept_connection)
t2 = threading.Thread(target=comunicate)
t3 = threading.Thread(target=exit_program)

t1.start()
t2.start()
t3.start()




