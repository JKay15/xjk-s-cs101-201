lis=[]
for i in range(int(input())):lis.append(set(input().split()[1:]))
for i in range(int(input())):
    tmp,ans=input(),[]
    for j in range(len(lis)):
        if tmp in lis[j]:ans.append(j+1)
    if len(ans):print(' '.join(map(str,ans)))
    else:print("NOT FOUND")