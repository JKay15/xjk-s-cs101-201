from heapq import heappop as hp
from heapq import heappush as hu
dic,num={},[]
for i in range(int(input())):
    num.append(input())
    dic[num[-1]]=i
edge=[[]for _ in range(len(num))]
for _ in range(int(input())):
    a,b,c=input().split()
    edge[dic[a]].append((dic[b],int(c)))
    edge[dic[b]].append((dic[a],int(c)))
ans=''
for _ in range(int(input())):
    s,e=input().split()
    q,sh,vis,ok=[(0,dic[s],dic[s])],{},[0 for _ in range(len(num))],''
    sh[dic[s]]=(dic[s],0)
    while len(q):
        z,x,y=hp(q)
        vis[x]=1
        if (x in sh and z<sh[x][1])or(x not in sh):sh[x]=(y,z)
        if x==dic[e]:
            cur=x
            ok+=num[x]
            while cur!=sh[cur][0]:
                ok=num[sh[cur][0]]+'->'+'('+str(sh[cur][1]-sh[sh[cur][0]][1])+')'+'->'+ok
                cur=sh[cur][0]
            ans+=ok+'\n'
            break
        for i in edge[x]:
            if not vis[i[0]]:hu(q,(z+i[1],i[0],x))
print(ans)