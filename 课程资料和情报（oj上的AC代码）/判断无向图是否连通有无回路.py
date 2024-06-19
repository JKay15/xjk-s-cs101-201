n,m=list(map(int,input().split()))
edge=[[]for _ in range(n)]
for _ in range(m):
    a,b=list(map(int,input().split()))
    edge[a].append(b)
    edge[b].append(a)
cnt,ok=set(),0
def dfs(x,y):
    global cnt,ok
    cnt.add(x)
    for i in edge[x]:
        if i not in cnt:dfs(i,x)
        elif y!=i:ok=1
for i in range(n):
    cnt.clear()
    dfs(i,-1)
    if len(cnt)==n:break
    if ok:break
print("connected:"+("yes"if len(cnt)==n else "no")+'\n'+"loop:"+('yes'if ok else 'no'))
