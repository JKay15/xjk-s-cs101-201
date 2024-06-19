from heapq import heappush as push
from heapq import heappop as pop
heap=[]
n=int(input())
for i in list(map(int,input().split())):
    push(heap,i)
ans=0
while len(heap)>1:
    t1,t2=pop(heap),pop(heap)
    ans+=(t1+t2)
    push(heap,t1+t2)
print(ans)
