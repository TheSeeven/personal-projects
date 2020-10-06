import threading
import sys
import socket
import signal

IP = sys.argv(1)
PORT = int(sys.argv(2))

INCOMING_SOCKET = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
INCOMING_SOCKET.bind((IP,PORT))

OUTGOING_SOCKET = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
OUTGOING_SOCKET.bind(('<broadcast>',7001))

def asking_user(): # Thread
    global OUTGOING_SOCKET
    global PORT
    while True:
        MESSAGE = PORT + ":" + str(input("Message to server: "))
        OUTGOING_SOCKET.sendto(bytes(MESSAGE,"utf-8"),(IP,PORT))
        print();


def check_incoming_messages(): # Thread
    while True:
        global INCOMING_SOCKET
        print("Message from: " + INCOMING_SOCKET.recvfrom(50)[1][1] + " with message: " + INCOMING_SOCKET.recvfrom(50)[0].decode());
        
def exit_program(): # Thread
    while True:
        try:
            pass
        except KeyboardInterrupt:
            sys.exit()

t1 = threading.Thread(target=asking_user)
t2 = threading.Thread(target=check_incoming_messages)
t3 = threading.Thread(target=exit_program)

t1.start()
t2.start()
t3.start()











