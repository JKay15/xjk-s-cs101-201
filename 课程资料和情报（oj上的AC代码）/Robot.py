from collections import deque
ans=''
def nex(d,l):
    if d==0:return (3 if l else 2)
    if d==1:return (2 if l else 3)
    if d==2:return (0 if l else 1)
    return (1 if l else 0)
while True:
    m,n=list(map(int,input().split()))
    if m==0:break
    bd1,vis,dx,dy=[list(map(int,input().split()))for _ in range(m)],[[0 for _ in range(n+1)]for _ in range(m+1)],[-1,1,0,0],[0,0,1,-1]
    bd=[[0 for _ in range(n+1)]for _ in range(m+1)]
    for i in range(m):
        for j in range(n):
            for x,y in ((0,0),(1,0),(0,1),(1,1)):
                bd[i+x][j+y]|=bd1[i][j]
    lis=input().split()
    b1,b2,e1,e2=list(map(int,lis[:-1]))
    dir=0 if lis[-1][0]=='n' else 1 if lis[-1][0]=='s' else 2 if lis[-1][0]=='e'else 3
    q=deque([[b1,b2,dir,0]])
    mm=-1
    while len(q):
        x,y,d,t=q.popleft()
        if x==e1 and y==e2:
            mm=t
            break
        for i in (1,2,3):
            xx,yy=x+dx[d]*i,y+dy[d]*i
            if (not(0<xx<m and 0<yy<n))or bd[xx][yy]:break
            if (not(vis[xx][yy]&(1<<d))):
                vis[xx][yy]|=(1<<d)
                q.append([xx,yy,d,t+1])
        for i in (0,1):
            if (not(vis[x][y]&(1<<nex(d,i)))):
                vis[x][y]|=(1<<nex(d,i))
                q.append([x,y,nex(d,i),t+1])
    ans+=str(mm)+"\n"
print(ans)
