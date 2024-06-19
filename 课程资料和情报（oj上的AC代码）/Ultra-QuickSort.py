lis=[]
def merge(l,r):
    global lis
    mid=(l+r)//2
    tmp,cur1,cur2,ans=[],l,mid+1,0
    while cur1<=mid and cur2<=r:
        if lis[cur1]<=lis[cur2]:
            tmp.append(lis[cur1])
            cur1+=1
        else:
            ans+=mid-cur1+1
            tmp.append(lis[cur2])
            cur2+=1
    tmp+=lis[cur1:mid+1]
    tmp+=lis[cur2:r+1]
    for i in range(l,r+1):lis[i]=tmp[i-l]
    return ans
            
def sorting(l,r):
    global lis
    if l==r:return 0
    mid=(l+r)//2
    ans=sorting(l,mid)
    ans+=sorting(mid+1,r)
    ans+=merge(l,r)
    return ans

while True:
    n=int(input())
    if not n:break
    lis=[]
    for i in range(n):lis.append(int(input()))
    print(sorting(0,n-1))
