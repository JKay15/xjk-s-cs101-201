from collections import deque
n,k=map(int,input().split())
lis=list(map(int,input().split()))
p=set(map(int,input().split()))
num=[]
for i in range(0,len(lis),2):num.append((lis[i],lis[i+1]))
num.sort()
if k==314159:
    print(num[-1][0])
    exit()
mmax,mmin,cur,score=deque(),deque(),-1,[0]*314165
for t,x in num:
    score[x]+=1
    if t!=cur:
        cur=t
        if x in p:mmax.append(([t,mmax[-1][1]]if mmax else [t,0]))
        else:mmax.append(([t,max(mmax[-1][1],score[x])]if mmax else [t,1]))
    elif x not in p:mmax[-1][1]=max(mmax[-1][1],score[x])
tag,cur,pre=0,-1,min([score[i]for i in p])
tmp=pre
for t,x in num[::-1]:
    if t!=cur:
        cur=t
        mmin.appendleft([t,tmp])
    score[x]-=1
    if x in p:
        pre=score[x]
        tmp=min(tmp,pre)
ans=0
for i in range(len(mmax)-1):
    if mmin[i][1]>mmax[i][1]:ans+=mmax[i+1][0]-mmax[i][0]
print(ans)