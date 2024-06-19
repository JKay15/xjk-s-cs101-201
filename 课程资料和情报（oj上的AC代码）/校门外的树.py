l,m=list(map(int,input().split()))
lis=[1 for i in range(l+1)]
for i in range(m):
    t1,t2=list(map(int,input().split()))
    for j in range(t1,t2+1):lis[j]=0
print(sum(lis))
