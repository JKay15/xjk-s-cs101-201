from collections import deque
n,m=list(map(int,input().split()))
bd,vis,dx,dy=[input()for _ in range(n)],[[0 for _ in range(m)]for _ in range(n)],[-1,1,0,0],[0,0,1,-1]
q=deque()
for i in range(n):
    for j in range(m):
        if bd[i][j]=='R':
            q.append(([(i,j)],0))
            vis[i][j]=-1
            break
    if len(q):break
ans=None
while len(q):
    lis,ok=q.popleft()
    x,y=lis[-1]
    for i in range(4):
        xx,yy=x+dx[i],y+dy[i]
        if 0<=xx<n and 0<=yy<m and ((ok==0 and vis[xx][yy]==0)or(ok and vis[xx][yy]<=0)) and bd[xx][yy]!='1':
            lis1=lis+[(xx,yy)]
            if bd[xx][yy]=='Y':
                vis[xx][yy]=1
                q.append((lis1,1))
            elif bd[xx][yy]=='C':
                if ok:
                    ans=lis1
                    break
                else:
                    vis[xx][yy]=-1
                    q.append((lis1,0))
            else:
                vis[xx][yy]=1 if ok else -1
                q.append((lis1,ok))
    if ans:break
for i in ans:print(str(i[0]+1)+' '+str(i[1]+1))