ans,tot="",0
def dfs(n,m,s):
    global ans,tot
    if n==0:
        ans+=s+"\n"
        tot+=1
        return
    if n<=m:return 
    for i in range(m+2,n+1,2):dfs(n-i,i,s+str(i)+' ')
dfs(int(input()),-1,"")
if ans:print(ans[:-1])
print(tot)
    