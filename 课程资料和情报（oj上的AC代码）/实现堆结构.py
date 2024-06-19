lis,size=[],0
def insert(i):
    global lis
    while lis[i]<lis[abs(i-1)//2]:
        lis[i],lis[abs(i-1)//2]=lis[abs(i-1)//2],lis[i]
        i=abs(i-1)//2
def pop():
    global lis,size
    ans=lis[0]
    lis[0],lis[size-1],i=lis[size-1],lis[0],0
    size=max(0,size-1)
    while i<size:
        best=i
        if 2*i+1<size and lis[2*i+1]<lis[i]:best=2*i+1
        if 2*i+2<size and lis[2*i+2]<lis[best]:best=2*i+2
        if best==i:break
        lis[i],lis[best]=lis[best],lis[i]
        i=best
    return ans

for i in range(int(input())):
    a=input()
    if a[0]=='1':
        size+=1
        b=list(map(int,a.split()))[1]
        if len(lis)<size:lis.append(b)
        else:lis[size-1]=b
        insert(size-1)
    else:print(pop())

