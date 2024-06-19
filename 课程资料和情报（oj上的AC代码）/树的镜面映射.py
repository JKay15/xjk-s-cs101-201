from collections import deque
n=int(input())
v,l,r,tot=[''for i in range(n)],[-1 for i in range(n)],[-1 for i in range(n)],0
def build(lis):
    global v,l,r,tot
    root=tot
    v[root]=lis[0][0]
    lis=lis[1:]
    tot+=1
    if len(lis):
        if lis[0][1]=='1':
            if lis[0][0]!='$':
                v[tot]=lis[0][0]
                l[root]=tot
                tot+=1
            lis=lis[1:]
        else:
            lc,lis=build(lis)
            l[root]=lc
    if len(lis):  
        if lis[0][1]=='1':
            if lis[0][0]!='$':
                v[tot]=lis[0][0]
                r[root]=tot
                tot+=1
            lis=lis[1:]
        else:
            rc,lis=build(lis)
            r[root]=rc
    return (root,lis)
tree=[[]for i in range(n)]
def build1(root):
    global tree,l,r
    ans=[root]
    if l[root]!=-1:tree[root].extend(build1(l[root]))
    if r[root]!=-1:ans.extend(build1(r[root]))
    return ans
def change(root):
    global tree
    tree[root]=tree[root][::-1]
    for i in tree[root]:change(i)
root,_=build(input().split())
build1(root)
change(root)
queue,ans=deque([root]),""
while len(queue):
    cur=queue.popleft()
    ans+=v[cur]+" "
    for i in tree[cur]:queue.append(i)
print(ans)
    

