cnt=1
while True:
    n,m=list(map(int,input().split()))
    if not n:break
    print("Case ",cnt,": ",sep="",end="")
    cnt+=1
    key=[i for i in range(n+1)]
    def father(i,key):
        if key[i]==i:return i
        ans=father(key[i],key)
        key[i]=ans
        return ans

    def union(x,y,key):
        fx=father(x,key)
        fy=father(y,key)
        key[fx]=fy

    for i in range(m):
        t1,t2=list(map(int,input().split()))
        union(t1,t2,key)
        
    ans=set()
    for i in range(1,n+1):ans.add(father(i,key))
    print(len(ans))