# 保存前缀的版本，是很慢的
ans=""
for _ in range(int(input())):
    l,p,ok=[input()for _ in range(int(input()))],set(),1
    l.sort(reverse=True)
    for i in l:
        if i in p:
            ok=0
            break
        cur=""
        for j in i:
            cur+=j
            p.add(cur)
    ans+=("YES"if ok else"NO")+"\n"
print(ans)
    
# 前缀树的版本——结果更慢了？？？
class node:
    def __init__(self):
        self.child=[None for _ in range(10)]
        self.have=0
ans=""
for _ in range(int(input())):
    root,ok=node(),1
    for _ in range(int(input())):
        str=input()
        if ok:
            cur=root
            for i in range(len(str)):
                if cur.child[int(str[i])]==None:
                    cur.child[int(str[i])]=node()
                    cur.have=1
                elif (i==len(str)-1) or(not cur.child[int(str[i])].have):
                    ok=0
                    break
                cur=cur.child[int(str[i])]
    ans+=("YES"if ok else"NO")+"\n"
print(ans)
                    
                    
                
    
