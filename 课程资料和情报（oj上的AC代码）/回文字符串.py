s=input()
dp=[[999 for i in range(len(s))]for j in range(len(s))]
for i in range(len(s)):dp[i][i]=0
# 考虑的长度
for i in range(2,len(s)+1):
    # 起点
    for j in range(len(s)-i+1):
        end=j+i-1
        if s[j]==s[end]:dp[j][end]=min(dp[j][end],dp[j+1][end-1]) if i>2 else 0
        else:
            #修改两端之一使其相等
            dp[j][end]=min(dp[j][end],1+(dp[j+1][end-1] if i>2 else 0))
            # 删除两端的可能
            dp[j][end]=min(dp[j][end],1+min(dp[j][end-1],dp[j+1][end]))
            # 在两端增加一个，使新的两端相等,和删除的递推没区别

print(dp[0][len(s)-1])



