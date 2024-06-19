from heapq import heappush as hu,heappop as hp
k,n,r=[int(input())for _ in range(3)]
edge,vis=[[]for _ in range(n+1)],[100000]*(n+1)
for _ in range(r):
    x,y,z,w=map(int,input().split())
    edge[x].append((y,z,w))
q,ans=[],-1
hu(q,(0,0,1))
while q:
    l,c,x=hp(q)
    if x==n:
        ans=l
        break
    vis[x]=c
    for y,z,w in edge[x]:
        if c+w<vis[y] and c+w<=k:hu(q,(l+z,c+w,y))
print(ans)