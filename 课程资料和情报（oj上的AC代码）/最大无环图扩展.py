n,m=map(int,input().split())
print(n*(n-1)//2-len(set([tuple(map(int,input().split()))for _ in range(m)])))