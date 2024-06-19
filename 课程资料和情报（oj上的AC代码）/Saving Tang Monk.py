# 蛇的问题
# vis数组更新时机的问题
from heapq import heappop as hp
from heapq import heappush as hu
ans=''
while True:
    n,m=list(map(int,input().split()))
    if n==0:break
    bd,vis,q,dx,dy,snake,cnt=[input()for _ in range(n)],[[-1 for _ in range(n)]for _ in range(n)],[],[1,-1,0,0],[0,0,1,-1],{},0
    for i in range(n):
        for j in range(n):
            if bd[i][j]=='K':
                hu(q,(0,0,0,i,j))
                vis[i][j]=0
            elif bd[i][j]=='S':
                snake[i*n+j]=cnt
                cnt+=1
    ok='impossible'
    while len(q):
        t,k,s,x,y=hp(q)
        if bd[x][y]=='T' and k==m:
            ok=str(t)
            break
        for i in range(4):
            xx,yy=x+dx[i],y+dy[i]
            if 0<=xx<n and 0<=yy<n and bd[xx][yy]!='#':
                if vis[xx][yy]>=k:continue
                vis[xx][yy]=k
                if '0'<bd[xx][yy]<='9':hu(q,(t+1,k,s,xx,yy)if int(bd[xx][yy])!=k+1 else (t+1,k+1,s,xx,yy))
                else:
                    if bd[xx][yy]=='S':
                        num=snake[xx*n+yy]
                        if s&(1<<num):hu(q,(t+1,k,s,xx,yy))
                        else:hu(q,(t+2,k,s|(1<<num),xx,yy))
                    else:hu(q,(t+1,k,s,xx,yy))
    ans+=ok+'\n'
print(ans)