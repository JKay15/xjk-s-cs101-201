T,M=list(map(int,input().split()))
t,v,dp=[],[],[0 for i in range(T+5)]
for i in range(M):
    t1,v1=list(map(int,input().split()))
    t.append(t1),v.append(v1)
for i in range(T,t[0]-1,-1):dp[i]=v[0]
for i in range(1,M):
    for j in range(T,0,-1):
        if j>=t[i]:dp[j]=max(dp[j],dp[j-t[i]]+v[i])
        else:break
print(dp[T])
