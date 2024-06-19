n,m=list(map(int,input().split()))
num=list(map(int,input().split()))
dp=[[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    dp[i][i]=(dp[i-1][i-1]+num[i] if i else num[i])
    dp[i][0]=(i+1)*dp[i][i]
for i in range(2,n):
    for j in range(1,m+1):
        if j>i:continue
        dp[i][j]=num[i]+dp[i-1][j-1]
        for k in range(j,i):dp[i][j]=min(dp[i][j],(i-k+1)*(num[i]+dp[i-1][i-1]-dp[k-1][k-1])+dp[k-1][j-1])
print(dp[n-1][m])