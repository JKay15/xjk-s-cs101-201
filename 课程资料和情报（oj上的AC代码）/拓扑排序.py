v,a=map(int,input().split())
edge,num,cnt,ans=[[]for _ in range(v+1)],[0]*(v+1),[1]*(v+1),''
for _ in range(a):
    x,y=map(int,input().split())
    edge[x].append(y)
    num[y]+=1
for i in range(v):
    for j in range(1,v+1):
        if cnt[j] and num[j]==0:
            ans+='v'+str(j)+' '
            cnt[j]=0
            for k in edge[j]:num[k]-=1
            break
print(ans)

    