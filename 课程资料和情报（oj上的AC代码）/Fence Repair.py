from heapq import heappop as hp1,heappush as hp2
lis,ans=[],0
for _ in range(int(input())):hp2(lis,int(input()))
while len(lis)>1:
    a,b=hp1(lis),hp1(lis)
    ans+=a+b
    hp2(lis,a+b)
print(ans)