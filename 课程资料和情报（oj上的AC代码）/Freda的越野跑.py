ans=0
n=int(input())
lis=list(map(int,input().split()))
def merge(l,r,m):
    tmp=[]
    cl,cr=l,m+1
    while cl<=m and cr<=r:
        if lis[cl]>=lis[cr]:
            tmp.append(lis[cl])
            cl+=1
        else:
            tmp.append(lis[cr])
            global ans
            ans+=m-cl+1
            cr+=1
    tmp.extend(lis[cl:m+1])
    tmp.extend(lis[cr:r+1])
    for i in range(l,r+1):lis[i]=tmp[i-l]
    
def sorting(l,r):
    if l==r:return 
    m=(l+r)//2
    sorting(l,m)
    sorting(m+1,r)
    merge(l,r,m)
sorting(0,n-1)
print(ans)
    