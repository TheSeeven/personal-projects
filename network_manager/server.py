import socket
import threading

import tools

HOST="127.0.0.1"
PORT=5000

soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
soc.bind((HOST, PORT))
soc.listen(100)

class Node:
    def __init__(self,val=None):
        self.val=val
        self.nextval=None

class LinkedList:
    def __init__(self):
        self.head=None

    def get_current(self):
        while self.head is None:
            pass
        return self.head.val
    
    def remove_current(self):
        self.head=self.head.nextval

    def add_node(self,node):
        if self.head is None:
            self.head=Node(node)
            return
        temp=self.head
        while temp.nextval is not None:
            temp=temp.nextval
        temp.nextval=Node(node)

List = LinkedList()

def get_connections():
    while True:
        try:
            List.add_node(soc.accept())
        except:
            print("an error ocured")

def execute_conenctions():
    while True:
        t=threading.Thread(target=execute_connection,args=(List.get_current(),))
        t.start()
        List.remove_current()

def execute_connection(task):
    data=False
    if task[0]!=None:
        GOT_SIZE=False
        SIZE = 1
        TEMP_SIZE=""
        while True:
            try:
                data=task[0].recv(SIZE)
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
            try:
                querry = tools.get_parse(data.decode())
                task[0].sendall(bytes(tools.parse_message(tools.parse_sql_data(tools.execute_querry(tools.get_connection(),querry[0],querry[1]))),'ASCII'))
            except Exception as e:
                print("lost connection to client " , e)
   

t1 = threading.Thread(target=get_connections)
t2 = threading.Thread(target=execute_conenctions)

t1.start()
t2.start()
