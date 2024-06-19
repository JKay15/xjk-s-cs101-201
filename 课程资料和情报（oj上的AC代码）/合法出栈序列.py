# 小心str可能都和一开始字符串不等长，或者其中的字符在原本的字符串中都没出现过
pos={j:i for i,j in enumerate(input())}
while True:
    try:str=input()
    except:break
    cur,lis,ok=0,[],1
    if len(str)!=len(pos):ok=0
    else:
        for i in str:
            if i not in pos:
                ok=0
                break
            if pos[i]<cur:
                if not len(lis) or lis[-1]!=pos[i]:
                    ok=0
                    break
                lis=lis[:-1]
            elif pos[i]==cur:
                cur+=1
            else:
                for j in range(cur,pos[i]):
                    lis.append(j)
                cur=pos[i]+1
    if ok:print("YES")
    else:print("NO")
                