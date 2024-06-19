ans=[]
def dfs(n,res,cnt):
    l=len(res)
    if l==2*n:
        ans.append(res)
        return 
    if cnt<n:
        dfs(n,res+'(',cnt+1)
        if l-cnt<cnt:dfs(n,res+')',cnt)
    elif cnt==n:dfs(n,res+')',cnt)
    return
dfs(int(input()),"",0)
print('\n'.join(ans))