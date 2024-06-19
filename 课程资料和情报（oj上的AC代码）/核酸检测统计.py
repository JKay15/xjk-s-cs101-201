from collections import defaultdict
s_c,s_lis,tot,num,n,m,ans,cur=defaultdict(str),defaultdict(list),defaultdict(int),defaultdict(int),int(input()),int(input()),0,[]
def check(lis):
    if lis[0]!=1:return 1
    cur=1
    for i in lis[1:]:
        if i-cur>3:return 1
        cur=i
    return (9-cur>=3)
for i in range(n):
    a,b=input().split()
    s_c[a],s_lis[a]=b,[]
    tot[b]+=1
for i in range(m):
    a,b=input().split()
    s_lis[b].append(int(a))

for i,j in s_lis.items():
    if check(sorted(j)):
        ans+=1
        num[s_c[i]]+=1
print(ans)
for i in tot.keys():cur.append((i,num[i]/tot[i]))
cur.sort(key=lambda x:x[1])
print(cur[-1][0])
    

    
