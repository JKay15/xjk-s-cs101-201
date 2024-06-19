N=int(input())
for cnt in range(N):
    print("Case "+str(cnt+1)+":")
    n,m,k=list(map(int,input().split()))
    friend=[set() for i in range(n+1)]
    for _ in range(m):
        a,b=list(map(int,input().split()))
        friend[a].add(b)
        friend[b].add(a)
    for _ in range(k):
        a,b=list(map(int,input().split()))
        print(len(friend[a].intersection(friend[b])))
    