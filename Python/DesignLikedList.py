class Node:
    def __init__(self, value = None, next = None):
        self.value = value
        self.next  = next

class MyLinkedList:

    def __init__(self):
        self.tail = Node()
        self.head = Node(None, self.tail)

    def get(self, index: int) -> int:

        pos = self.head
        
        i = 0

        if (index <= 0):
            return -1
        
        while pos:
            if i == index:
                return pos.value        
            pos = pos.next
        
        return -1
    
    def addAtHead(self, val: int) -> None:
        novo = Node(val, self.head.next)
        self.head.next = novo

    def addAtTail(self, val: int) -> None:
        pass

    def addAtIndex(self, index: int, val: int) -> None:
        pass

    def deleteAtIndex(self, index: int) -> None:
        pass


    def mostrar(self):
        pos = self.head
        while pos:
            print(f"{pos.value}", end=" ")
            pos = pos.next
        print()

obj = MyLinkedList()
obj.addAtHead(10)
obj.addAtHead(20)
print(obj.get(1))
obj.mostrar()

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)