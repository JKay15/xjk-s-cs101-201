ans=''
while True:
    n,m=list(map(int,input().split()))
    if n+m==0:break
    f,num=[i for i in range(n)],[1]*n
    def ff(x):
        global f
        if x!=f[x]:f[x]=ff(f[x])
        return f[x]
    def union(x,y):
        global f,num
        fx,fy=ff(x),ff(y)
        if fx==fy:return 
        f[fy]=fx
        num[fx]+=num[fy]
    for _ in range(m):
        lis=list(map(int,input().split()))
        for i in lis[2:]:union(lis[1],i)
    ans+=str(num[ff(0)])+'\n'
print(ans)