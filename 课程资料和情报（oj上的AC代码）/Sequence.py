# from heapq import heappush as hu,heappop as hp
# cur=''
# for _ in range(int(input())):
#     m,n=map(int,input().split())
#     lis=[sorted(list(map(int,input().split())))for _ in range(m)]
#     q,ans=[],[]
#     hu(q,(sum([x[0]for x in lis]),[0]*m))
#     while len(ans)<n:
#         s,num=hp(q)
#         ans.append(s)
#         for i in range(m):
#             if (t:=num[i])<n-1:hu(q,(s-lis[i][t]+lis[i][t+1],num[:i]+[t+1]+num[i+1:]))
#     cur+=' '.join(map(str,ans))+'\n'
# print(cur)
from heapq import heappush as hu,heappop as hp
cur=''
for _ in range(int(input())):
    m,n=map(int,input().split())
    c=sorted(map(int,input().split()))
    for _ in range(m-1):
        a,b=c.copy(),sorted(map(int,input().split()))
        q=[]
        hu(q,(a[0]+b[0],0,0,0))
        for i in range(n):
            s,x,y,pre=hp(q)
            c[i]=s
            if i==n-1:break
            hu(q,(a[x]+b[y+1],x,y+1,1))
            if pre==0:hu(q,(a[x+1]+b[y],x+1,y,0))
    cur+=' '.join(map(str,c))+'\n'
print(cur)
