from heapq import heappop,heappush,heapify
input()
lis,ans=list(map(int,input().split())),0
heapify(lis)
while len(lis)>1:
    a,b=heappop(lis),heappop(lis)
    ans+=(a+b)
    heappush(lis,a+b)
print(ans)