import math
vis,prime=[0 for i in range(10005)],[]
for i in range(2,10005):
    if not vis[i]:prime.append(i)
    j,c=0,len(prime)
    while j<c and i*prime[j]<10005:
        vis[i*prime[j]]=1
        if i%prime[j]==0:break
        j+=1
prime=set(prime)
def t_prime(n):
    t=int(math.sqrt(n))
    if t*t==n and t in prime:return 1
    return 0

m,n=list(map(int,input().split()))
for i in range(m):
    lis=list(map(int,input().split()))
    ans=[]
    for i in lis:
        if t_prime(i):ans.append(i)
    print(0 if not len(ans) else "%.2f"%(sum(ans)/len(lis)))
    