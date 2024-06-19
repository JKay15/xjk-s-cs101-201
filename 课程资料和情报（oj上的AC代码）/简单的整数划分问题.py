def dfs(i,m,dp):
    if i<=1:return 1
    m,ans=min(i,m),0
    if dp[i][m]:return dp[i][m]
    for j in range(m,0,-1):ans+=dfs(i-j,j,dp)
    dp[i][m]=ans
    return ans
while True:
    try:m=int(input())
    except:break
    dp=[[0 for j in range(m+5)] for i in range(m+5)]
    print(dfs(m,m,dp))
    