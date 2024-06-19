import sys
import heapq
inf = float("inf")
n,m,k = map(int, sys.stdin.readline().split())
g = {i:[] for i in range(1, n+1)}
vis = [[False]*(k+1) for _ in range(n+1)]
dist = [[inf]*(k+1) for _ in range(n+1)]
for _ in range(m):
    u,v,w = map(int, sys.stdin.readline().split())
    g[u].append((v, w))
    g[v].append((u, w))
def dijkstra(r = 1):
    q = []
    dist[r][0] = 0
    heapq.heappush(q, (0, r, 0)) 
    while q:
        x,i,j = heapq.heappop(q)
        if vis[i][j]: continue
        vis[i][j] = True
        for v,w in g[i]:
            if dist[v][j] > max(x, w):
                dist[v][j] = max(x, w)
                heapq.heappush(q, (dist[v][j], v, j))
            if j < k and dist[v][j+1] > x:
                dist[v][j+1] = dist[i][j]
                heapq.heappush(q, (dist[v][j+1], v, j+1))
dijkstra(1)
ans = inf
for i in range(k+1):ans = min(dist[n][i], ans)
print(ans if ans != inf else -1)