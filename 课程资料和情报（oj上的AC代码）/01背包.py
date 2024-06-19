n,m=list(map(int,input().split()))
v,w=[],[]
for i in range(n):
    t1,t2=list(map(int,input().split()))
    if t2<=m:w.append(t1),v.append(t2)
n=len(v)
dp=[v[0] if i>=w[0] else 0 for i in range(m+1)]
for i in range(1,n):
    for j in range(m,w[i]-1,-1):dp[j]=max(dp[j],v[i]+dp[j-w[i]])
print(dp[m])