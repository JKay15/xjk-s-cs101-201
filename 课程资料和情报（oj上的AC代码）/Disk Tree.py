# 这个写法存在一个巨大的问题，就是不同文件夹中的同名文件夹，我们无法区分，于是这种抽象方法失败了，写类吧
# dict,root,tree,tot={},set(),[],0
# def dfs(str,n):
#     ans=' '*n+str+"\n"
    
    
# for _ in range(int(input())):
#     na=input().split('\\')
#     root.add(na[0])
#     if na[0] not in dict:
#         tree[tot]=na[0]
#         dict[na[0]]=[tot]
#         cur=tot
#         tot+=1
#     else:cur=dict[na[0]][0]
#     for i in na[1:]:
#         if i not in dict:
#             tree[tot]=i
#             dict[i]=[tot]
#             dict[tree[cur]].append(tot)
#             cur=tot
#             tot+=1
#         elif i not in dict[tree[cur]]:
#             dict[tree[cur]].append(dict[i][0])
#             cur=dict[i][0]
#         else:cur=dict[i][0]
#     for i in list(root).sort():
class node:
    def __init__(self):
        self.p=dict()
        self.child=[]
root=node()
for _ in range(int(input())):
    na=input().split('\\')
    cur=root
    for i in na:
        if i not in cur.p:
            cur.p[i]=len(cur.child)
            cur.child.append(node())
        cur=cur.child[cur.p[i]]
def dfs(cur,str,n):
    ans=" "*n+str+"\n"
    for i in sorted(list(cur.p.keys())):
        ans+=dfs(cur.child[cur.p[i]],i,n+1)
    return ans
ans,x="",sorted(list(root.p.keys()))
for i in x:
    ans+=dfs(root.child[root.p[i]],i,0)
print(ans)
            
            