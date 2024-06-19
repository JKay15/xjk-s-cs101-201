n,m=list(map(int,input().split()))
f,sq=[i for i in range(n*m)],[input() for _ in range(n)]
def find_x(i,f):
    if f[i]==i:return i
    fx=find_x(f[i],f)
    f[i]=fx
    return fx
def union(i,j,f):
    fx,fy=find_x(i,f),find_x(j,f)
    f[fy]=fx
for i in range(n):
    for j in range(m):
        if sq[i][j]!='W':continue
        if i>0 and sq[i-1][j]=="W":union((i-1)*m+j,i*m+j,f)
        if j>0 and sq[i][j-1]=='W':union(i*m+j-1,i*m+j,f)
        if i>0 and j>0 and sq[i-1][j-1]=='W':union((i-1)*m+j-1,i*m+j,f)
        if i>0 and j<m-1 and sq[i-1][j+1]=='W':union((i-1)*m+j+1,i*m+j,f)
ans=0
for i in range(n):
    for j in range(m):
        if sq[i][j]=='W'and f[i*m+j]==i*m+j:ans+=1
print(ans)