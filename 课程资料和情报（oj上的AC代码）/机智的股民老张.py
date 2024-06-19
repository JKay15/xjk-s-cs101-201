lis=list(map(int,input().split()))
mmin,ans=10000000,0
for i in lis:
    ans=max(ans,max(0,i-mmin))
    mmin=min(mmin,i)
print(ans)

