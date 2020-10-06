import sys
import re
import math
import itertools

INPUTip = sys.argv[1]
INPUTnetwork = sys.argv[2]


def check_input(ip):
    if re.match(r"^\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}/\d{1,3}$", ip):
        return True
    return False


def check_newtorknumber(number):
    try:
        if(int(number) == 0 or int(number) > 4211669250):
            return False
        return True
    except:
        return False


if not check_input(INPUTip):
    sys.exit('invalid ip')

if not check_newtorknumber(INPUTnetwork):
    sys.exit('invalid network number')

SCHEMA = [128, 64, 32, 16, 8, 4, 2, 1]
COMBINATIONS = []



class Adress:
    def __init__(self, string):
        self.ip = []
        self.cidr = None
        temp = ''
        for i in string:
            if i is not '.' and i is not '/':
                temp += i
            if i is '.' or i is '/':
                self.ip.append(int(temp))
                temp = ''
        self.cidr = int(temp)

    def __str__(self):
        return "{i1}.{i2}.{i3}.{i4}".format(i1=self.ip[0],i2=self.ip[1],i3=self.ip[2],i4=self.ip[3])

    def solve(self):
        for i in COMBINATIONS:
            self.ip[get_pos(self.cidr)]=i
            for j in range(get_pos(self.cidr)+1,len(self.ip)):
                self.ip[j]=0
            print("NetworkId: ", self, "  prefix: " ,self.cidr)
            print("minid: ",self, end = "")
            try:  
                for q in range(get_pos(self.cidr)+1,len(self.ip)):
                    self.ip[q]=255
                self.ip[get_pos(self.cidr)]=COMBINATIONS[COMBINATIONS.index(self.ip[get_pos(self.cidr)])+1]-1
                print("        maxid: ",self,"\n")
            except:
                for q in range(get_pos(self.cidr)+1,len(self.ip)):
                    self.ip[q]=255
                self.ip[get_pos(self.cidr)]=255
                print("        maxid: ",self,"\n")

def get_pos(cidr):
    return int(cidr/8)


def new_cidr(cidr):
    return int(math.log(cidr, 2))


def get_combinations(nr):
    pass

addr = Adress(INPUTip)
addr.cidr+=new_cidr(int(INPUTnetwork))

for i in range(new_cidr(int(INPUTnetwork)),len(SCHEMA)):
    del SCHEMA[-1]

temp1 = []
for L in range(0, len(SCHEMA)+1):
    for subset in itertools.combinations(SCHEMA, L):
        temp1.append(subset)
temp2=0
for i in temp1:
    for j in i:
        temp2+=j
    COMBINATIONS.append(temp2)
    temp2=0
COMBINATIONS.sort()

print(COMBINATIONS)
addr.solve()