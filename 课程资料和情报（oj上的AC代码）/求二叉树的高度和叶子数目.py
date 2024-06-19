n=int(input())
c=[list(map(int,input().split())) for i in range(n)]
l=[-1 for i in range(n)]
ans=set()
def dfs(i):
    global l,ans,c
    if l[i]!=-1:return l[i]
    if c[i][0]==-1 and c[i][1]==-1:
        ans.add(i)
        l[i]=0
        return 0
    if c[i][0]==-1:l[i]= 1+dfs(c[i][1])
    elif c[i][1]==-1:l[i]= 1+dfs(c[i][0])
    else:l[i]= 1+max(dfs(c[i][0]),dfs(c[i][1]))
    return l[i]
ans1=0
for i in range(n):ans1=max(ans1,dfs(i))
print(ans1,len(ans))


