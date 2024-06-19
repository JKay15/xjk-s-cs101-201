class node:
    def __init__(self,val):
        self.c=[]
        self.val=val
        
def build(s):
    l=len(s)
    if l==1:return node(s)
    root=node(s[0])
    tmp,lis,num,cur="",[],0,2
    while cur<l-1:
        if tmp=="":
            tmp+=s[cur]
            if s[cur+1]==')'or s[cur+1]==',':
                lis.append(tmp)
                cur+=1
                tmp=""
            else:
                cur+=1
                tmp+=s[cur]
                num+=1
        else:
            if s[cur]!=')':
                tmp+=s[cur]
                if s[cur]=='(':num+=1
            else:
                tmp+=s[cur]
                num-=1
                if not num:
                    cur+=1
                    lis.append(tmp)
                    tmp=""
        cur+=1
    for i in lis:root.c.append(build(i))
    return root
def dfs(root,t):
    s=root.val if t else ""
    for i in root.c:s+=dfs(i,t) if i else ""
    s+="" if t else root.val
    return s
        
root=build(input())
print(dfs(root,1),dfs(root,0),sep="\n")

