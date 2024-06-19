from collections import deque
def bfs(n):
    q,vis=deque([(1%n,'1')]),[0 for _ in range(n)]
    while 1:
        cn,cur=q.popleft()
        if cn==0:
            print(cur)
            return
        a,b=(cn*10)%n,(cn*10+1)%n
        if vis[a]==0:
            vis[a]=1
            q.append((a,cur+'0'))
        if vis[b]==0:
            vis[b]=1
            q.append((b,cur+'1'))
while 1:
    n=int(input())
    if n==0:break
    bfs(n)