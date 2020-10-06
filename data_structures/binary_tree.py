class Node():
    def __init__(self,data,left=None,right=None):
        self.left=left
        self.right=right
        self.data=data
    
class Tree():
    def __init__(self, root=None):
        self.root=root
    
    def show_tree(self):
        if self.root is None:
            print("Arborele nu are nici un element!")
        else:
            self._show_tree(self.root)
    
    def _show_tree(self,curent):
        if curent is not None:
            self._show_tree(curent.right)
            print(curent.data)
            self._show_tree(curent.left)

    def _add_data(self,value,curent):
        if value > curent.data:
            if curent.right is None:
                curent.right=Node(value)
            else:
                self._add_data(value,curent.right)
        elif value < curent.data:
            if curent.left is None:
                curent.left=Node(value)
            else:            
                self._add_data(value,curent.left)

    def add_data(self,value):
        if self.root is None:
            self.root=Node(data=value)
        else:
            self._add_data(value,self.root)           

    def search(self,key):
        current=self.root
        while current!=key:
            if current.right is None and current.left is None:
                print("Arborele are un singur element.")
            elif current.right is None and curent.left is not None:
                current=curent.left
                search(curent.left)
            elif current.left is None and curent.right is not None:
                current=curent.right
                search(curent.right)
            elif current.right is not None and current.left is not None:
                if key > current.data:
                    return current.right.search()
                else:
                    return current.left.search(
        
        return current
    




tree=Tree()

tree.add_data(10)
tree.add_data(12)
tree.add_data(13)
tree.add_data(14)
tree.add_data(15)
tree.add_data(5)
tree.add_data(6)
tree.add_data(4)
tree.add_data(3)
tree.add_data(2)
tree.show_tree()
print(tree.search(10),"  Numarul acesta exista!")