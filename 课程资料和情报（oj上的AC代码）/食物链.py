n,k=list(map(int,input().split()))
f,ans=[i for i in range(n*3+1)],0
def find_x(x):
    global f
    if f[x]==x:return x
    f[x]=find_x(f[x])
    return f[x]
def union(x,y):
    global f
    fx,fy=find_x(x),find_x(y)
    f[fx]=fy
for _ in range(k):
    d,x,y=list(map(int,input().split()))
    if (x>n or y>n)or(d==2 and x==y):
        ans+=1
        continue
    fx1,fx2,fx3,fy=find_x(x),find_x(n+x),find_x(n*2+x),find_x(y)
    if (d==1 and (fx2==fy or fx3==fy)) or (d==2 and (fx1==fy or fx3==fy)):
        ans+=1
        continue
    if d==1:
        union(x,y)
        union(x+n,y+n)
        union(x+2*n,y+2*n)
    else:
        union(x,2*n+y)
        union(y,n+x)
        union(x+2*n,y+n)
print(ans)