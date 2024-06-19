from collections import deque
vis=[0 for i in range(100004)]
n,k=list(map(int,input().split()))
queue,ans,vis[n]=deque([(n,0)]),0,1
while len(queue):
    cur=queue.popleft()
    a,b,c,d=cur[0]+1,cur[0]-1,cur[0]*2,cur[1]+1
    if a<=100000 and not vis[a]:
        if a==k:
            ans=d
            break
        vis[a]=1
        queue.append((a,d))
    if b>=0 and not vis[b]:
        if b==k:
            ans=d
            break
        vis[b]=1
        queue.append((b,d))
    if c<=100000 and not vis[c]:
        if c==k:
            ans=d
            break
        vis[c]=1
        queue.append((c,d))
print(ans)
