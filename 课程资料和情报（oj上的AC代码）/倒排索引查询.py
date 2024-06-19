lis,lis1,total=[],[],set()
for _ in range(int(input())):
    lis.append(set(list(map(int,input().split()))[1:]))
    total=total|lis[-1]
for i in lis:lis1.append(total.difference(i))
for _ in range(int(input())):
    ans=total.copy()
    for num,i in enumerate(input().split()):
        if i=='0':continue
        if i=='1':ans.intersection_update(lis[num])
        else:ans.intersection_update(lis1[num])
    if not len(ans):print("NOT FOUND")
    else:print(' '.join(map(str,sorted(list(ans)))))