n,k=list(map(int,input().split()))
lis=[int(input())for _ in range(n)]
def check(l):
    global lis,k
    ans=0
    for i in lis:ans+=int(i/l)
    return (ans>=k)
l,r,ans=1,max(lis),0
while l<=r:
    mid=int((l+r)/2)
    if check(mid):
        ans=mid
        l=mid+1
    else:r=mid-1
print(ans)

