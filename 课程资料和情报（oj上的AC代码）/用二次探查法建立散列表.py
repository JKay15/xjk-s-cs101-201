import sys
y=list(map(int,sys.stdin.read().split()))
n,m=y[0],y[1]
d,vis,dic,ans=y[2:2+n],[0]*m,[0]*m,[]
for i in d:
    h,cur=i%m,1
    while vis[h] and dic[h]!=i:
        if cur>0:
            h=(i+cur*cur)%m
            cur*=-1
        else:
            h=(i-cur*cur)%m
            cur=-cur+1
    vis[h],dic[h]=1,i
    ans.append(str(h))
print(' '.join(ans))
    
