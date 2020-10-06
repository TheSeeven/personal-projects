import socket
import sys
import threading
import time
import re

CLIENT_USERNAME = str(sys.argv[1])
SERVER_IP = str(sys.argv[2])
SERVER_PORT = 7000
CLIENT_USERNAME_TARGET = str(input("Introduceti numele destinatarului: "))
time.sleep(2)

connectionTCP=socket.socket()

connectionUDP = socket.socket(socket.AF_INET,socket.SOCK_DGRAM,socket.IPPROTO_UDP)
connectionUDP.sendto(bytes("<server>chat<server>","utf-8"), ("192.168.1.255",7000))
connectionUDP.settimeout(2)


def get_ip(s): # This function returns the ip from a known kind of String
    points = 0
    ip=""
    for i in s:
        if i == "." or i == "/":
            points+=1
        if points < 4:
            ip+=i
    if points < 4:
        return False
    else:    
        return ip

def get_port(s): # This function returns the port from a known kind of String
    bracket = False
    port = ""
    for i in s:
        if i is "/":
            bracket = True
            continue
        if bracket == True:
            port+=i
    return int(port)

def check_data(s): # Return True if the folowing string looks like an ip adress
    if re.match(r"^\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}/5009$",s) is not None:
        return True
    return False

def try_connect():
    MESAJ_PRIMIRE = ""
    NOT_CONNECTED = True
    while NOT_CONNECTED:
        try:
            data=connectionUDP.recv(22)
            MESAJ_PRIMIRE+=data.decode("utf-8")
            if check_data(MESAJ_PRIMIRE):
                IP = get_ip(MESAJ_PRIMIRE)
                PORT = get_port(MESAJ_PRIMIRE)
                NOT_CONNECTED = False
                return (IP,PORT)
        except socket.timeout:
            print("Connection to server failed... Retrying") 

def receive(): # Thread
    while True:
        MSG = ""
        data=connectionTCP.recv(50)
        if data != bytes("{quit}","utf-8"):
            MSG+=data.decode("utf-8")
        print(MSG)

def listen(): # Loop
    t1 = threading.Thread(target=receive)
    t1.start() 

    global CLIENT_USERNAME
    global CLIENT_USERNAME_TARGET

    while True:
        try:
            x = str(input())
            connectionTCP.send(bytes(CLIENT_USERNAME_TARGET + ":" + x,"utf-8"))
            print("          >%s: " % (CLIENT_USERNAME) + x)
        except:
            print("Eroare de conectare la server!")

def connect(PORTIP):
    global CLIENT_USERNAME

    try:
        connected = False
        while not connected:
            try:
                connectionTCP.connect((PORTIP[0],PORTIP[1]))
                connected=True
                print("connection established")
            except:
                print("server not found")
                time.sleep(2)
        connectionTCP.send(bytes("register:" + CLIENT_USERNAME,"utf-8"))
        data=connectionTCP.recv(1)

        if data.decode("utf-8") == 'Y':
            listen()
        else:
            connectionTCP.close()
            print("Deja este cineva cu acest nume!")
    except Exception as err:
        return err

try:
    PORTIP = try_connect()
    connect(PORTIP)
except:
    print("Eroare de conectare la server!")
    connectionTCP.close()
    exit()
exit()








