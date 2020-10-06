import socket
import threading
import time

SERVER_IP="192.168.1.108"
SERVER_PORT=5009

connectionUDP = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
connectionUDP.setsockopt(socket.SOL_SOCKET,socket.SO_BROADCAST,1)
connectionUDP.bind(("",7000))

serverTCP = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serverTCP.bind((SERVER_IP,SERVER_PORT))
serverTCP.listen(5)

REGISTERED_CLIENTS = [] # Clientii inregistrati
MESSAGE_QUEUE = []      # Coada de mesaje in asteptare
LOG = []           # Coada de comenzi primite

class Conexiune:
    def __init__(self,name,connection):
        self.name=name
        self.connection=connection

    def __str__(self):
        return self.name + ":"+self.connection[1][0]+":"+str(self.connection[1][0])

class Mesaj:
    def __init__(self,name,message,dest):
        self.name=name
        self.dest=dest
        self.message=message

    def __str__(self):
        return self.name + " -> " + self.dest + " :"+self.message

def log(msg):
    LOG.append(msg)

def get_name(big_msg):
    msg = ""
    points = False
    for i in big_msg:
        if i != ":" and points == False:
            continue
        if i == ":":
            points = True
        elif points == True:
            msg += i
    return msg

def get_user(big_msg):
    name = ""
    for i in big_msg:
        if i == ":" :
            break
        else:
            name+=i
    return name

def get_message(big_msg):
    message= ""
    points = False
    for i in big_msg:
        if points == True:
            message+=i 
        if i == ":":
            points = True
    return message

def check_register(msg):
    keyword = ""
    for i in msg:
        if i == ":":
            break
        else:
            keyword += i
    if keyword == "register":
        return True
    else:
        return False

def check_client(client):
    global REGISTERED_CLIENTS

    for i in REGISTERED_CLIENTS:
        if i.name==get_name(client):
            return False
    return True

def messenger(client,run): # Thread
    global REGISTERED_CLIENTS
    global MESSAGE_QUEUE
    global LOG

    while run:
        MSG = ""
        try:
            data = client.connection[0].recv(1024)
            if data != bytes("{quit}","utf-8"):
                MSG += data.decode("utf-8")
            MSG = Mesaj(client.name,get_message(MSG),get_user(MSG))
            MESSAGE_QUEUE.append(MSG)
            
            log(str(MSG))
            print(str(MSG))

        except:
            client.connection[0].close()
            print(client.name + " disconnected")
            log(client.name + " disconnected")
            REGISTERED_CLIENTS.remove(client)
            run=False

def registry(): # Thread
    global REGISTERED_CLIENTS
    global LOG

    while True:
        connection = serverTCP.accept()
        name = connection[0].recv(40).decode("utf-8")
        CONN = Conexiune(get_name(name),connection)
        if check_register(name) == True:
            if check_client(name):
                
                connection[0].send(bytes('Y',"utf-8"))
                REGISTERED_CLIENTS.append(CONN)

                t = threading.Thread(target=messenger,args=(CONN,True))
                t.start()

                print(str(CONN.name) + " connected")
                log(str(CONN.name) + " connected")

            elif not check_client(name):
                connection[0].send(bytes('N',"utf-8"))
                connection[0].close()

                print(str(CONN.name) + " connection failed")
                log(str(CONN.name) + " connection failed")

def send_message(): # Thread
    global REGISTERED_CLIENTS
    global MESSAGE_QUEUE
    global LOG

    while True:
        for msg in MESSAGE_QUEUE:
            for client in REGISTERED_CLIENTS:
                if msg.dest == client.name:
                    try:
                        MESSAGE = "<" + msg.name + ": " + msg.message
                        client.connection[0].send(bytes(MESSAGE,"utf-8"))
                        MESSAGE_QUEUE.remove(msg)
                        break
                    except Exception as err:
                        print(msg.name + "->" + msg.dest + " failed")
                        log(msg.name + "->" + msg.dest + " failed")
                        MESSAGE_QUEUE.remove(msg)

def check_incoming_connection(): # Thread
    while True:
        data=connectionUDP.recvfrom(20)
        if data[0].decode() == "<server>chat<server>":
            data.sendto(bytes("127.0.0.1/5009"),data[1])

def print_users():
    for i in REGISTERED_CLIENTS:
        print(i.name + ":"+i.connection[1][0] + ":"+ str(i.connection[1][1]) + " ; ", end ='')
    print()

def log_printer(): # Thread
    global LOG
    while True:
        time.sleep(5.0)
        print_users()
        

t1 = threading.Thread(target=registry)
t3 = threading.Thread(target=send_message)
t4 = threading.Thread(target=log_printer)
t5 = threading.Thread(target=log_printer)

t1.start()
t3.start()
t4.start()
t5.start()

time.sleep(2)

print("The server is running!")



