n,m=list(map(int,input().split()))
graph=[[0 for _ in range(n)]for _ in range(n)]
for _ in range(m):
    a,b=list(map(int,input().split()))
    graph[a][a]+=1
    graph[b][b]+=1
    graph[a][b]-=1
    graph[b][a]-=1
print("\n".join([' '.join(map(str,i)) for i in graph]))