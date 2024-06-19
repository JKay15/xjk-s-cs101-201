#这里能想到枚举两个点，并且将最后的结果除以4就好了，就是算坐标有点无聊
ans=''
while 1:
    n=int(input())
    if n==0:break
    p,s,cur=[],set(),0
    for _ in range(n):
        a,b=map(int,input().split())
        p.append((a,b))
        s.add((a,b))
    for i in range(n):
        for j in range(i+1,n):
            x1,y1,x2,y2=p[i][0],p[i][1],p[j][0],p[j][1]
            dx,dy=x1-x2,y1-y2
            if (x1-dy,y1+dx) in s and (x2-dy,y2+dx) in s:cur+=1
            if (x1+dy,y1-dx) in s and (x2+dy,y2-dx) in s:cur+=1
    ans+=str(cur//4)+'\n'
print(ans)