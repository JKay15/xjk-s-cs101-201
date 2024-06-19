str1=input()
while True:
    str2=input()
    if str2!="":break
dp=[[0 for i in range(len(str2))]for j in range(len(str1))]

for i in range(len(str1)):dp[i][0]=1 if (str1[i]==str2[0])else 0
for i in range(len(str2)):dp[0][i]=1 if(str2[i]==str1[0])else 0
for i in range(1,len(str1)):
    for j in range(1,len(str2)):
        dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]))
        if str1[i]==str2[j]:dp[i][j]=max(dp[i][j],1+dp[i-1][j-1])
print(dp[len(str1)-1][len(str2)-1])