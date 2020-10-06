import os

class Nod():
    def __init__(self,item,adress=None):
        self.item=item
        self.adress=adress

class List():
    def __init__(self,first=None):
        self.first=first

    def add_first(self):
        os.system('cls')
        x=int(input("Introduceti datele care doriti sa le adaugati: "))
        element=Nod(x)
        if self.first is None:   
            self.first=element
            print("\nLista este:")
            self.display()
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        else:
            element.adress=self.first
            self.first=element
            print("\nLista este:")
            self.display()
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()  
    
    def add_last(self):
        os.system('cls')
        x=int(input("Introduceti datele care doriti sa le adaugati: "))
        element=Nod(x)
        temp=self.first
        if self.first is None:
            self.first=element
            print("\nLista este:")
            self.display()
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        else:
            while temp.adress != None:
                temp=temp.adress
            temp.adress=element
            print("\nLista este:")
            self.display()
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
 
    def add_middle(self):
        os.system('cls')
        x=int(input("In fata carui numar doriti sa il adaugati? "))
        y=int(input("\nCe numar doriti sa adaugati? "))
        element=Nod(y)
        temp=self.first
        while temp.item != x and temp.adress != None: 
            temp=temp.adress
        if temp.item==x:    
            element.adress=temp.adress
            temp.adress=element
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        else:
            os.system('cls')
            print("Elementul nu a fost gasit!")
            input("Apasati enter pentru a reveni in meniu.")
            menu()
    
    def display(self): 
        temp=self.first
        while temp != None:
            print(temp.item)
            temp=temp.adress            

    def remove_first(self):
        if self.first != None:
            self.first=self.first.adress
            print("\nLista este:")
            self.display()
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        else:
            print("Lista nu are nici un element!")
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()

    def remove_last(self):
        if self.first == None:
            print("Lista nu are nici un element!")
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        elif self.first.adress == None:
            self.first = None
            os.system('cls')
            print("Ultimul element a fost sters!")
            input("Apasati enter pentru a reveni in meniu.")
            menu()
        else:
            temp=self.first
            while temp.adress.adress is not None:
                temp=temp.adress
            temp.adress=None
            os.system('cls')
            print("Ultimul element a fost sters!")
            input("Apasati enter pentru a reveni in meniu.")
            menu()
    
    def remove_middle(self):
        if self.first == None:
            os.system('cls')
            print("Lista nu are nici un element!")
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        else:
            os.system('cls')
            x=int(input("Introduceti numarul care doriti sa il stergeti: "))
            temp=self.first
            prev=None
            while temp.item != x and temp.adress is not None:
                prev=temp
                temp=temp.adress
            if temp.item==x:
                prev.adress=temp.adress
                os.system('cls')
                print("Elementul {} a fost eliminat!".format(x))
                input("Apasati enter pentru a reveni in meniu.")
                menu()
            else:
                os.system('cls')
                print("Elementul nu exista!")
                input("Apasati enter pentru a reveni in meniu.")
                menu()

    def count(self):
        os.system('cls')
        temp=self.first
        contor=1
        if self.first is not None:   
            while temp.adress!=None:
                temp=temp.adress
                contor+=1
            print("Numarul de elemente este: ", contor)
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
        else:
            os.system('cls')
            print("Lista este goala!")
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
    
    def index(self):
        x=int(input("Introduceti indexul cautat: "))
        os.system('cls')
        temp=self.first
        contor=1
        if self.first is not None:   
            while contor!=x and temp.adress is not None:
                temp=temp.adress
                contor+=1
            if temp.adress is None:
                os.system('cls')
                print("Indexul dat este prea mare!")
                input("Apasati enter pentru a reveni in meniu.")
                os.system('cls')
                menu()
            else:
                print("Elementul este: ", temp.item)
                input("Apasati enter pentru a reveni in meniu.")
                os.system('cls')
                menu()
        else:
            os.system('cls')
            print("Elementul nu exista!")
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()
    
    def first_n(self):
        x=int(input("Cate elemente doriti sa afisati: "))
        temp=self.first
        contor=0
        if self.first is not None:
            while temp.adress is not None and contor!=x:
                temp=temp.adress
                contor+=1
                print(temp.item)

            input("\nApasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()

        else:
            os.system('cls')
            print("Lista este goala!")
            input("Apasati enter pentru a reveni in meniu.")
            os.system('cls')
            menu()


head=List()

def search():
    x=int(input
    (
'''Ce optiune doriti?
1. Numarul de elemente
2. Cautare dupa index
Optiune: '''
))
    if x >= 1 and x<=2: # This directs you mto different functions you want to make
        if x==1:
            os.system('cls')
            head.count()
        else:
            os.system('cls')
            head.index()


def remove():
    x=int(input
    (
'''Care element doriti sa il stergeti?
1. Primul
2. Ultimul
3. In mijlocul listei
Optiune: '''
))

    if x >= 1 and x<=3: # This directs you mto different functions you want to make
        if x==1:
            os.system('cls')
            head.remove_first()
        elif x==2:
            os.system('cls')
            head.remove_last()
        elif x==3:
            os.system('cls')
            head.remove_middle()
        else:
            os.system('cls')
            remove()
    else: # In this case, a wrong number was introduced from menu
        print("\nIntroduceti un numar valid!\n")


def add():
    os.system('cls')
    x=int(input
    (
'''Unde doriti sa adaugati elementul?
1. La inceputul listei
2. La sfarsitul listei
3. La mijlocul listei
4. Reintoarcere in meniu
Optiune: '''
))

    if x >= 1 and x<=3: # This directs you mto different functions you want to make
        
        if x==1:
            head.add_first()
        elif x==2:
            head.add_last()
        elif x==3:
            head.add_middle()
        else:
            os.system('cls')
            menu()
    else: # In this case, a wrong number was introduced from main menu
        print("\nIntroduceti un numar valid!\n")
        add()

def menu():   # This is the main menu, it is an GUI
    try:
        x=int(input
        (
'''Introduceti o optiune: 
1. Adaugati un element
2. Eliminati un element
3. Cautati un element
4. Afisati toata lista
5. Afisati primul element
6. Primele "n" elemente
Optiune: '''
))
        

        if x >= 1 and x<=6: # This directs you mto different functions you want to make
            
            if x==1:
                os.system('cls')
                add()
            elif x==2:
                os.system('cls')
                remove()
            elif x==3:
                os.system('cls')
                search()  
            elif x==4:
                os.system('cls')
                print("Lista este:")
                head.display()
                print("\n")
                menu()
            elif x==5:
                os.system('cls')
                print("Primul element este: ", head.first.item, "\n")
                menu()
            else:
                os.system('cls')
                head.first_n()
                menu()
         
        else: # In this case, a wrong number was introduced from main menu
            os.system('cls')
            print("Introduceti un numar valid!\n")
            menu()
    except ValueError:
        os.system('cls')
        print("Introduceti un numar!\n")
        menu()

menu()