from collections import deque
ans=''
for _  in range(int(input())):
    r,c,k=list(map(int,input().split()))
    bd,vis,dx,dy=[input() for _ in range(r)],[[0 for _ in range(c)]for _ in range(r)],[1,-1,0,0],[0,0,1,-1]
    for i in range(r):
        for j in range(c):
            if bd[i][j]=='S':q=deque([(i,j,0)])
    cur='Oop!'
    while len(q):
        x,y,t=q.popleft()
        if bd[x][y]=='E':
            cur=str(t)
            break
        for i in range(4):
            xx,yy=x+dx[i],y+dy[i]
            if 0<=xx<r and 0<=yy<c and (not (vis[xx][yy]&(1<<((t+1)%k)))):
                vis[xx][yy]|=(1<<((t+1)%k))
                if bd[xx][yy]!='#' or ((t+1)%k==0):q.append((xx,yy,t+1))
    ans+=cur+'\n'
print(ans)