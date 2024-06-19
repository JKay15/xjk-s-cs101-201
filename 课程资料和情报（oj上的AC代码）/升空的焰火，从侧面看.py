n=int(input())
l,r=[-1]*(n+1),[-1]*(n+1)
for i in range(1,n+1):l[i],r[i]=map(int,input().split())
q,ans=[1],''
while q:
    ans+=str(q[-1])+' '
    tmp=[]
    for i in q:
        if l[i]!=-1:tmp.append(l[i])
        if r[i]!=-1:tmp.append(r[i])
    q=tmp
print(ans)
