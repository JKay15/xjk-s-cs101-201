# 简单的单调栈而已
ans,cnt=[],0
while True:
    try:t=input()
    except:break
    if t[1]=='o':
        while len(ans)and ans[-1][1]>=cnt:ans=ans[:-1]
        cnt-=1
    elif t[1]=='u':
        _,n=t.split()
        n=int(n)
        if len(ans):
            if n<ans[-1][0]:ans.append([n,cnt+1])
        else:ans.append([n,cnt+1])
        cnt+=1
    else:
        if len(ans):print(ans[-1][0])