class Node:
    def __init__(self, value = None, next = None):
        self.value = value
        self.next  = next

class MyLinkedList:
    def __init__(self):
        self.head = Node(None, None)

    def get(self, index: int) -> int:
        pos = self.head.next
        i = 0
        if (index < 0):
            return -1
        while pos:
            if i == index:
                return pos.value
            i += 1        
            pos = pos.next
        return -1
    
    def addAtHead(self, val: int) -> None:
        novo = Node(val, self.head.next)
        self.head.next = novo

    def addAtTail(self, val: int) -> None:
        pos = self.head
        while pos.next != None:
            pos = pos.next
        new_node = Node(val)
        pos.next = new_node

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0:
            index = 0
        i = 0
        pos = self.head
        while pos != None and i < index:
            pos = pos.next
            i += 1
        if pos == None:
            return
        new_node = Node(val, pos.next)
        pos.next = new_node
        
    def deleteAtIndex(self, index: int) -> None:
        if index < 0:
            return
        ant = self.head
        i = 0
        while ant.next != None and i < index:
            ant = ant.next
            i += 1
        if ant.next == None:
            return
        temp = ant.next
        ant.next = temp.next
        del temp

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)