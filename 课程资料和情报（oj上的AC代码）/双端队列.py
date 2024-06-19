class Deque:
    def __init__(self):
        self.items=[]
    def isEmpty(self):
        return self.items==[]
    def addFront(self,n):
        self.items.append(n)
    def addRear(self,n):
        self.items.insert(0,n)
    def removeFront(self):
        return self.items.pop()
    def removeRear(self):
        return self.items.pop(0)
    def size(self):
        return len(self.items)
    

for i in range(int(input())):
    d=Deque()
    for j in range(int(input())):
        a,b=list(map(int,input().split()))
        if a==1:d.addRear(b)
        else: d.removeFront() if b==0 else d.removeRear()
    if d.isEmpty():print("NULL")
    else:print(' '.join(map(str,d.items[::-1])))

    