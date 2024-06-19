def f(n,m):
    if m==1:return n
    if n==1:return 1
    return ((f(n-1,m)-1)+m)%n+1
while True:
    n,m=list(map(int,input().split()))
    if not n:break
    print(f(n,m))
    
    