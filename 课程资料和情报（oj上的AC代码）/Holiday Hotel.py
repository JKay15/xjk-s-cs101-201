while True:
    lis=[]
    n,ans,c=int(input()),0,1000000
    if not n:break
    for i in range(n):lis.append(list(map(int,input().split())))
    lis.sort()
    for i in lis:
        if i[1]<c:
            ans+=1
            c=i[1]
    print(ans)  