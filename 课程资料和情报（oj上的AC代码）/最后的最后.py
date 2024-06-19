n,k=list(map(int,input().split()))
a,cur=[i for i in range(1,n+1)],0
for i in range(n-1):
    cur=(cur+k-1)%len(a)
    print(a[cur],end=" ")
    a=a[:cur]+a[cur+1:]