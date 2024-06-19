m,n=list(map(int,input().split()))
def num(n,k,dp):
    if n==0 or k==1:return 1
    if n<k:return num(n,n,dp)
    if dp[n][k]!=-1:return dp[n][k]
    dp[n][k]=num(n,k-1,dp)+num(n-k,k,dp)
    return dp[n][k]

dp=[[-1 for i in range(n+1)]for j in range(m+1)]
print(num(m,n,dp))