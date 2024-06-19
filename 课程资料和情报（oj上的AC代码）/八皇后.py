ans,col,r,l=[],[0 for _ in range(8)],[0 for _ in range(16)],[0 for _ in range(16)]
def dfs(n,s):
    global ans,col,r,l
    if n==8:
        ans.append(s)
        return 
    for i in range(8):
        if not col[i] and not r[i+n] and not l[n-i+8]:
            col[i]=r[i+n]=l[n-i+8]=1
            dfs(n+1,s+str(i+1))
            col[i]=r[i+n]=l[n-i+8]=0
dfs(0,'')
for _ in range(int(input())):print(ans[int(input())-1])
    
        