n,w=list(map(int,input().split()))
lis=[]
for i in range(n):lis.append(list(map(int,input().split())))
lis.sort(reverse=True,key=lambda x:x[0]/x[1])
cur,ans=0,0
for i in lis:
    if cur+i[1]<w:ans+=i[0]
    else:
        ans+=i[0]*(w-cur)/i[1]
        break
    cur+=i[1]
print("%.1f"%ans)