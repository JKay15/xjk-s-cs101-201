n,m=list(map(int,input().split()))
out=[int(input())for _ in range(n)]
l,r,ans=max(out),sum(out),0
def check(x):
    global out,m,n
    res,i,tot=m,0,0
    while res>0 and i<n:
        if tot+out[i]<=x:tot+=out[i]
        else:
            res-=1
            if res==0:return 0
            tot=out[i]
        i+=1
    if i==n:return 1
    return 0
while l<=r:
    mid=(l+r)//2
    if check(mid):
        ans=mid
        r=mid-1
    else:l=mid+1
print(ans)