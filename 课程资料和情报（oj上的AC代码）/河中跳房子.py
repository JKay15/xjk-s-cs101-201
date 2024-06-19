l,n,m=list(map(int,input().split()))
d=[int(input()) for _ in range(n)]+[l]
for i in range(n,0,-1):d[i]=d[i]-d[i-1]
l,r,ans=min(d),l,0
def check(x):
    global d,n,m
    res,tot=0,0
    for i in range(n+1):
        if tot+d[i]<x:
            res+=1
            tot+=d[i]
        else:tot=0
    return res<=m
while l<=r:
    mid=(l+r)//2
    if check(mid):
        ans=mid
        l=mid+1
    else:r=mid-1
print(ans)
