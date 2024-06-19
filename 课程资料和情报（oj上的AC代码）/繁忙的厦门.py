# n,m=map(int,input().split())
# edge=sorted([list(map(int,input().split()))for _ in range(m)],key=lambda x:x[2])
# f,num=[],[]
# l,r,ans1=edge[0][2],edge[-1][2],-1
# def ff(x):
#     global f
#     if f[x]!=x:f[x]=ff(f[x])
#     return f[x]
# def union(x,y):
#     global f,num
#     fx,fy=ff(x),ff(y)
#     if fx!=fy:num[fx]+=num[fy]
#     f[fy]=fx
# while l<=r:
#     f=[i for i in range(n+1)]
#     mid,num,cur,tmp=(l+r)//2,[1]*(n+1),0,0
#     for i in edge:
#         if i[2]<=mid:
#             cur,tmp=i[0],max(tmp,i[2])
#             union(i[0],i[1])
#         else:break
#     if cur and num[ff(cur)]==n:
#         ans1=tmp
#         r=mid-1
#     else:l=mid+1
# print(n-1,ans1)

# n,m=map(int,input().split())
# edge=sorted([list(map(int,input().split()))for _ in range(m)],key=lambda x:x[2])
# f,ans,tot=[i for i in range(n+1)],0,0
# def ff(x):
#     global f
#     if f[x]!=x:f[x]=ff(f[x])
#     return f[x]
# def union(x,y):
#     global f
#     fx,fy=ff(x),ff(y)
#     f[fy]=fx
# for i in edge:
#     if ff(i[0])!=ff(i[1]):
#         union(i[0],i[1])
#         ans=max(ans,i[2])
#         tot+=1
#     if tot==n-1:break
# print(n-1,ans)
from heapq import heappop as hp,heappush as hu
n,m=map(int,input().split())
edge,ans=[],0
for _ in range(m):
    a,b,c=map(int,input().split())
    hu(edge,(c,a,b))
v=set([1])
while len(v)<n:
    tmp=[hp(edge)]
    c,x,y=tmp[0]
    while not((x in v and y not in v)or(x not in v and y in v)):
        tmp.append(hp(edge))
        c,x,y=tmp[-1]
    v.add(x if x not in v else y)
    ans=max(ans,c)
    for i in tmp:
        if i[1] not in v or i[2] not in v:hu(edge,i)
print(n-1,ans)
        