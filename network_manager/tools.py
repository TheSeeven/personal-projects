import mysql.connector as sql
import datetime


def parse_message(message):
    HEAD  = len(message)
    return str(HEAD)+":"+message

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
            DB=sql.connect(host="127.0.0.110",user="clients",passwd="",buffered=True,database="public_transport",auth_plugin='mysql_native_password')
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

