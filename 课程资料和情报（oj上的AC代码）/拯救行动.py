from heapq import heappush as hp
from heapq import heappop as hp1
ans=''
for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    lis,dx,dy,vis=[input()for _ in range(n)],[-1,1,0,0],[0,0,1,-1],[[0 for _ in range(m)]for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if lis[i][j]=='r':
                b1,b2=i,j
                break
    q=[(0,b1,b2)]
    ok='Impossible'
    while len(q):
        t,x,y=hp1(q)
        if lis[x][y]=='a':
            ok=str(t)
            break
        for i in range(4):
            xx,yy=x+dx[i],y+dy[i]
            if 0<=xx<n and 0<=yy<m and (not vis[xx][yy]) and lis[xx][yy]!='#':
                vis[xx][yy]=1
                if lis[xx][yy]=='x':
                    hp(q,(t+2,xx,yy))
                else:
                    hp(q,(t+1,xx,yy))
    ans+=ok+'\n'
print(ans)
                    
                
            
        