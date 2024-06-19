import sys
y=list(map(int,sys.stdin.read().split()))
n,m=y[0],y[1]
num=y[2:2+n]
vis,dic,ans=[0]*m,[0]*m,[]
for i in num:
    h=i%m
    while vis[h] and dic[h]!=i:h=(h+1)%m
    vis[h],dic[h]=1,i
    ans.append(h)
print(' '.join(map(str,ans)))