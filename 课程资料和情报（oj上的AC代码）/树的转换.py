class node:
    def __init__(self):
        self.c=[]
        self.cl,self.cr=None,None
def build(s):
    root=node()
    while len(s)and s[0]=='d':
        s=s[1:]
        s,c=build(s)
        root.c.append(c)
    else:s=s[1:]
    return s,root
def trans(root,by):
    if by:root.cr=by
    if len(root.c):root.cl=root.c[0]
    for i in range(len(root.c)):
        if i+1<len(root.c):trans(root.c[i],root.c[i+1])
        else:trans(root.c[i],None)
def dfs(root,tag):
    ans=0
    if tag:
        if root.cl:ans=max(ans,dfs(root.cl,tag)+1)
        if root.cr:ans=max(ans,dfs(root.cr,tag)+1)
    else:
        for i in root.c:ans=max(ans,dfs(i,tag)+1)
    return ans
root=build(input())[1]
trans(root,None)
print(dfs(root,0),"=>",dfs(root,1),sep=' ')

    