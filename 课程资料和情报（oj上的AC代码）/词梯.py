from collections import deque,defaultdict as dd
lis=['']+[input() for _ in range(int(input()))]
buc,adj,vis=dd(list),[[]for _ in range(len(lis))],[0 for _ in range(len(lis))]
num={j:i for i,j in enumerate(lis)}
for i in lis[1:]:
    for j in range(4):
        buc[i[:j]+'_'+i[j+1:]].append(i)
for i,l in buc.items():
    for i1 in l:
        for i2 in l:
            if i1!=i2:adj[num[i1]].append(num[i2])
s,e=input().split()
vis[num[s]],vis[num[e]],q=num[s],-num[e],deque([num[s],num[e]])  
def dfs(i):
    global vis
    if i==abs(vis[i]):return [lis[i]]
    return [lis[i]]+dfs(abs(vis[i]))
ans=""
while len(q):
    cur=q.popleft()
    for i in adj[cur]:
        if not vis[i]:
            vis[i]=(cur if vis[cur]>0 else -cur)
            q.append(i)
        else:
            if vis[i]*vis[cur]<0:
                a,b=dfs(cur),dfs(i)
                if vis[i]>0:ans=b[::-1]+a
                if vis[cur]>0:ans=a[::-1]+b
                break
    if ans!="":break
print(' '.join(ans) if ans!="" else "NO")
# from collections import deque
# lis=['']
# for _ in range(int(input())):lis.append(input())
# dic,adj,vis=set(lis[1:]),[[]for _ in range(len(lis))],[0 for _ in range(len(lis))]
# num={j:i for i,j in enumerate(lis)}
# for i in range(1,len(lis)):
#     for j in range(4):
#         for p in [chr(i+ord('a'))for i in range(26)]+[chr(i+ord('A'))for i in range(26)]:
#             if p==lis[i][j]:continue
#             t=lis[i][:j]+p+lis[i][j+1:]
#             if t in dic:adj[i].append(num[t])      
# s,e=input().split()
# ans=[]
# def h(str):
#     global e
#     ans=0
#     for i in range(4):
#         if lis[str][i]!=e[i]:ans+=1
#     return ans
# def dfs(str,d,maxd):
#     global vis,e,ans,adj
#     if d+h(str)>=maxd:return False
#     ans.append(lis[str])
#     if lis[str]==e:return True
#     for i in adj[str]:
#         if not vis[i]:
#             vis[i]=1
#             if dfs(i,d+1,maxd):return True
#             vis[i]=0
#     ans=ans[:-1]
#     return False
    
# for maxd in range(1,len(lis)):
#     if dfs(num[s],0,maxd):break
# if ans!=[]:print(' '.join(ans))
# else:print("NO")

    
# vis[num[s]],vis[num[e]],q=num[s],-num[e],deque([num[s],num[e]])  
# def dfs(i):
#     global vis
#     if i==abs(vis[i]):return [lis[i]]
#     return [lis[i]]+dfs(abs(vis[i]))
# ans=""
# while len(q):
#     cur=q.popleft()
#     for i in adj[cur]:
#         if not vis[i]:
#             vis[i]=(cur if vis[cur]>0 else -cur)
#             q.append(i)
#         else:
#             if vis[i]*vis[cur]<0:
#                 a,b=dfs(cur),dfs(i)
#                 if vis[i]>0:ans=b[::-1]+a
#                 if vis[cur]>0:ans=a[::-1]+b
#                 break
#     if ans!="":break
# print(' '.join(ans) if ans!="" else "NO")


                
                


