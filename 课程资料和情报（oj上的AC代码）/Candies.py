from heapq import heappop as hp,heappush as hu
n,m=map(int,input().split())
edge,vis=[[]for _ in range(n+1)],[0]*(n+1)
for _ in range(m):
    x,y,z=map(int,input().split())
    edge[x].append((y,z))
q,ans=[],0
hu(q,(0,1))
while q:
    l,p=hp(q)
    if p==n:
        ans=l
        break
    vis[p]=1
    for x,y in edge[p]:
        if vis[x]==0:hu(q,(l+y,x))
print(ans)