import socket
import threading
import time

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 5000        # The port used by the server


# soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
# soc.connect((HOST,PORT))



def function1():
    while True:
        time.sleep(1)
        soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        soc.connect((HOST,PORT))  
        soc.sendall(b'12:function1$')
        data = soc.recv(100).decode()
        print('function1 - ', repr(data))
        soc.close()


def function2():
    while True:
        time.sleep(2)
        soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        soc.connect((HOST,PORT)) 
        soc.sendall(b'11:function2$')
        data = soc.recv(100).decode()
        print('function2 - ', repr(data))
        soc.close()

def function3():
    while True:
       
        soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        soc.connect((HOST,PORT))
        time.sleep(3)
        soc.sendall(b'10:function3')
        data = soc.recv(100).decode()
        print('function3 - ', repr(data))
        soc.close()

def function4():
    while True:
       
        soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        soc.connect((HOST,PORT))
        time.sleep(1)
        soc.sendall(b'10:function4')
        data = soc.recv(100).decode()
        print('function3 - ', repr(data))
        soc.close()

def function5():
    while True:
       
        soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        soc.connect((HOST,PORT))
        time.sleep(0.5)
        soc.sendall(b'10:function5')
        data = soc.recv(100).decode()
        print('function3 - ', repr(data))
        soc.close()

def function6():
    while True:
       
        soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        soc.connect((HOST,PORT))
        time.sleep(0.1)
        soc.sendall(b'10:function6')
        data = soc.recv(100).decode()
        print('function3 - ', repr(data))
        soc.close()



t1 = threading.Thread(target=function1)
t2 = threading.Thread(target=function2)
t3 = threading.Thread(target=function3)
t4 = threading.Thread(target=function4)
t5 = threading.Thread(target=function5)
t6 = threading.Thread(target=function6)

t1.start()
t2.start()
t3.start()
t4.start()
t5.start()
t6.start()