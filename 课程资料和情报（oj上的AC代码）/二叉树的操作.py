ans=''
for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    f,l,r=[-1 for _ in range(n)],[-1 for _ in range(n)],[-1 for _ in range(n)]
    for _ in range(n):
        a,b,c=list(map(int,input().split()))
        f[b],f[c]=(a,0),(a,1)
        l[a],r[a]=b,c
    for _ in range(m):
        lis=list(map(int,input().split()))
        if lis[0]==1:
            f1,f2=f[lis[1]],f[lis[2]]
            if f1[1]:r[f1[0]]=lis[2]
            else:l[f1[0]]=lis[2]
            if f2[1]:r[f2[0]]=lis[1]
            else:l[f2[0]]=lis[1]
            f[lis[1]],f[lis[2]]=f2,f1
        else:
            cur=lis[1]
            while l[cur]!=-1:cur=l[cur]
            ans+=str(cur)+'\n'
print(ans)
    