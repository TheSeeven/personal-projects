import socket
import threading
import mysql.connector as sql
import datetime
from tools import *

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


def get_parse(message):
    counter=0
    querry = ""
    params= []
    temp_str = ""
    for i in message:
        if i == "[":
            counter += 1
            continue
        elif i ==";":
            params.append(temp_str)
            temp_str=""
            continue
        elif i=="]":
            if temp_str !="":
                params.append(temp_str)
            return(str(querry),params)
        if counter == 0:
            querry+=i
        elif counter == 1:
            temp_str+=i
    return ""

def parse_sql_data(data):
    if data != False:
        result =""
        for i in data:
            for j in i:
                result+=str(j)
                result+=','
            result = result.rstrip(',')
            result+=';'
        return result
    return "Invalid Request!"

def get_connection():
    while True:
        try:
            DB=sql.connect(host="192.168.1.110",user="clients",passwd="",buffered=True,database="public_transport",auth_plugin='mysql_native_password')
            DB.autocomit= True
            return DB
        except:
            print("error creating connection ", datetime.datetime.now())

def execute_querry(DB,procName,parameters):
    DBCURSOR=DB.cursor()
    try:
        DBCURSOR.callproc(procName,parameters)
        for i in DBCURSOR.stored_results():
            rez = i.fetchall()
        DB.close()
        return rez
    except Exception as e:
        print(" error executing querry ", e)
        DB.close()
        return False

def get_connections():
    while True:
        try:
            List.add_node(soc.accept())
        except:
            print("an error ocured")

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
                querry = get_parse(data.decode())
                b = execute_querry(get_connection(),querry[0],querry[1])
                a= parse_sql_data(b)
                x = bytes(parse_message(a),'ASCII')
                task[0].sendall(x)
            except Exception as e:
                print("lost connection to client " , e)

def execute_conenctions():
    while True:
        t=threading.Thread(target=execute_connection,args=(List.get_current(),))
        t.start()
        List.remove_current()
        

t1 = threading.Thread(target=get_connections)
t2 = threading.Thread(target=execute_conenctions)

t1.start()
t2.start()
