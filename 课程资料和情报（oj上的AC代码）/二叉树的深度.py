n=int(input())
tree=[[-1,-1] for i in range(n+1)]
def dfs(tree,i):
    ans=1
    if tree[i][0]!=-1:ans=max(ans,1+dfs(tree,tree[i][0]))
    if tree[i][1]!=-1:ans=max(ans,1+dfs(tree,tree[i][1]))
    return ans

for i in range(1,n+1):
    t1,t2=list(map(int,input().split()))
    tree[i]=[t1,t2]
    
print(dfs(tree,1))
