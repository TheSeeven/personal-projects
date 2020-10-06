class Nod():
    def __init__(self,data,left=None,right=None):
        self.left=left
        self.right=right
        self.data=data

class List():
    def __init__(self,first=None):
        self.first=first
    

    def add_front(self,x):
        element=Nod(x)
        
        if self.first is None:
            self.first=element

        else:
            element.right=self.first
            self.first.left=element
            self.first=element
    
    def add_end(self,x):
        element=Nod(x)
        
        temp=self.first
        while temp.right is not None:
            temp=temp.right
        temp.right=element
        element.left=temp

    def add_middle(self,x,y):
        element=Nod(x)
        contor=1
        temp=self.first

        while temp.right is not None and contor!=y: 
            temp=temp.right
            contor+=1
        
        temp.left.right=element
        element.right=temp
        
        element.left=temp.left
        temp.left=element

    def delete_middle(self,x):
        temp=self.first
        contor=1
        while temp.right is not None and x!=contor:
            temp=temp.right
            contor+=1
        temp.left.right=temp.right
        temp.right.left=temp.left
        temp.right=None
        temp.left=None


    def display(self):
        temp=self.first
        print(temp.data)
        while temp.right is not None:
            temp=temp.right
            print(temp.data)


first=List()

first.add_front(1)
first.add_front(2)
first.add_front(3)
first.add_front(4)
first.add_front(5)
first.add_front(6)
first.add_front(7)
first.add_front(8)
first.add_front(9)


def menu():
    first.display()
    x=int(input("\nOptiune: "))

    if x==1:
        y=int(input("\nValoare de adaugat: "))
        first.add_front(y)
        print("\n")
        menu()

    elif x==2:
        y=int(input("\nValoare de adaugat: "))
        first.add_end(y)
        print("\n")
        menu()
    
    elif x==3:
        x=int(input("\nValoare de adaugat: "))
        y=int(input("\nLa a care pozitie: "))
        first.add_middle(x,y)
        print("\n")
        menu()
    
    elif x==4:
        x=int(input("Introduceti indexul de sters: "))
        first.delete_middle(x)
        print("\n")
        menu()

    elif x==5:
        print("\n")
        menu()
menu()





