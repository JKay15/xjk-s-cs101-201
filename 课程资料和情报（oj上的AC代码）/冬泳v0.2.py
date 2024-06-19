n=int(input())
mint,minv,ans=0x7777777,-0x7777777,0
d=list(map(int,input().split()))
t=list(map(int,input().split()))
a=list(map(int,input().split()))
for i in range(n-1):
    if (a[i]<mint or d[i]/a[i]>minv) and a[i]<t[i]:
        ans+=1
    mint=min(mint,a[i])
    minv=max(minv,d[i]/a[i])
print(ans)