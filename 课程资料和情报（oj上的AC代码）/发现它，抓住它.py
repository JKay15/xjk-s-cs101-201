set,a=[],[]
def find_set(i):
    global set,a
    if i==set[i]:return set[i]
    t=find_set(set[i])
    a[i]=(a[i]+a[set[i]])%2
    set[i]=t
    return t
def union(i,j):
    t1,t2=find_set(i),find_set(j)
    set[t1]=t2
    if a[j]==0:a[t1]=1-a[i]
    else:a[t1]=a[i]
    
for i in range(int(input())):
    n,m=list(map(int,input().split()))
    set,a,ans=[i for i in range(n+2)],[0 for i in range(n+2)],""
    for i in range(m):
        x,y,z=input().split()
        y,z=int(y),int(z)
        if x=='A':
            fx,fy=find_set(y),find_set(z)
            if fx!=fy:ans+="Not sure yet.\n"
            elif a[y]==a[z]:ans+="In the same gang.\n"
            else:ans+="In different gangs.\n"
        else:union(y,z)
    print(ans,end="")
    