from functools import cmp_to_key as cp
def cmp(a,b):
    x,y=sum(a[1][0]),sum(b[1][0])
    if x==y:
        if a[1][1]==b[1][1]:
            if a[0]<b[0]:return -1
            return 1
        elif a[1][1]<b[1][1]:return -1
        return 1
    elif x>y:return -1
    return 1
dic={}
for _ in range(int(input())):
    a,b,c=input().split(',')
    if a in dic:dic[a][1]+=1
    else:dic[a]=[[0 for _ in range(26)],1]
    if c=='yes':dic[a][0][ord(b)-ord('A')]=1
ans=sorted(list(dic.items()),key=cp(cmp))
for i in range(min(len(ans),12)):print(str(i+1),ans[i][0],sum(ans[i][1][0]),ans[i][1][1])