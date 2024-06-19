def find_x(i,f):
    if i==f[i]:return i
    fx=find_x(f[i],f)
    f[i]=fx
    return fx
def union(i,j,f):
    fx,fy=find_x(i,f),find_x(j,f)
    if fx==fy:return 'Yes'
    f[fy]=fx
    return 'No'
ans=""
while True:
    try:n,m=list(map(int,input().split()))
    except:break
    f=[i for i in range(n+1)]
    for _ in range(m):
        x,y=list(map(int,input().split()))
        ans+=union(x,y,f)+"\n"
    cur=[i for i in range(1,n+1) if f[i]==i]
    ans+=str(len(cur))+"\n"+' '.join(map(str,cur))+"\n"
print(ans)
        
    
    