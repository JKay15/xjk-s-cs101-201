import heapq as hp
_,lis,ans=input(),list(map(int,input().split())),0
hp.heapify(lis)
while len(lis)>1:
    a,b=hp.heappop(lis),hp.heappop(lis)
    ans+=a+b
    hp.heappush(lis,a+b)
print(ans)

