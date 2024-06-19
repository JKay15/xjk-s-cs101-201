ans,lis,dp="",[],[]
def dfs(c1,c2):
    global lis,dp
    c3=c1+c2
    if c3>=len(lis[2]):return 1
    if dp[c1][c2]!=-1:return dp[c1][c2]
    cur=0
    if c1>=len(lis[0]):
        if lis[1][c2]!=lis[2][c3]:
            dp[c1][c2]=0
            return 0
        else:cur=max(cur,dfs(c1,c2+1))
    elif c2>=len(lis[1]):
        if lis[0][c1]!=lis[2][c3]:
            dp[c1][c2]=0
            return 0
        else:cur=max(cur,dfs(c1+1,c2))
    else:
        if lis[0][c1]==lis[2][c3]:cur=max(cur,dfs(c1+1,c2))
        if cur:
            dp[c1][c2]=1
            return 1
        if lis[1][c2]==lis[2][c3]:cur=max(cur,dfs(c1,c2+1))
    dp[c1][c2]=cur
    return cur

for i in range(int(input())):
    dp=[[-1 for j in range(203)]for p in range(203)]
    ans+="Data set "+str(i+1)+": "
    lis=input().split()
    ans+='yes\n' if dfs(0,0)else 'no\n'
print(ans)