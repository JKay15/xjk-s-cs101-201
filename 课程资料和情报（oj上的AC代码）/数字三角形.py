n=int(input())
lis,dp=[list(map(int,input().split())) for i in range(n)],[[-1 for i in range(j+1)]for j in range(n)]
def dfs(i,j,n):
    if i==n-1:return lis[i][j]
    if dp[i][j]!=-1:return dp[i][j]
    dp[i][j]=lis[i][j]+max(dfs(i+1,j,n),dfs(i+1,j+1,n))
    return dp[i][j]
print(dfs(0,0,n))
