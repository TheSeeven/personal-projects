import socket
import threading
import time
import tools

HOST = '192.168.1.110'  # The server's hostname or IP address
PORT = 3301        # The port used by the server


def execute_querry(message):
    GOT_SIZE=False
    SIZE = 1
    TEMP_SIZE=""
    data=False

    soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    soc.connect((HOST,PORT))
    soc.sendall(bytes(tools.parse_message(message),'ASCII'))

    while True:
        try:
            data=soc.recv(SIZE)
        except:
            break
        if not GOT_SIZE:
            try:
                temp=int(data.decode())
                TEMP_SIZE+=str(temp)
                continue
            except:
                SIZE=int(TEMP_SIZE)
                GOT_SIZE=True
                continue
        break
    if data:
        return data.decode()

    soc.close()
    return False


def function6():
    print(execute_querry("get_types[]"))

while(True):
    t1 = threading.Thread(target=function6)
    t1.start()
    time.sleep(2)
