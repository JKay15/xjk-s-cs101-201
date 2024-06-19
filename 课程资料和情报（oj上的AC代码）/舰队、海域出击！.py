# cur=''
# for _ in range(int(input())):
#     try:n,m=list(map(int,input().split()))
#     except:break
#     vis,edge=[0]*(n+5),[[]for _ in range(n+1)]
#     for _ in range(m):
#         a,b=list(map(int,input().split()))
#         edge[a].append(b)
#     def dfs(x,f):
#         global vis,edge
#         vis[x],aa=1,0
#         for i in edge[x]:
#             if vis[i]==0 and edge[i]:aa=dfs(i,f+[i])
#             elif i in f:return 1
#             if aa:return 1
#         return 0
#     ans=0
#     for i in range(1,n+1):
#         if edge[i] and vis[i]==0:
#             ans=dfs(i,[i])
#             if ans:break
#     cur+=(('Yes'if ans else'No')+'\n')
# print(cur)
# cur=''
# for _ in range(int(input())):
#     try:n,m=list(map(int,input().split()))
#     except:break
#     vis,edge,num=[0]*(n+1),[[]for _ in range(n+1)],[0]*(n+1)
#     for _ in range(m):
#         a,b=list(map(int,input().split()))
#         edge[a].append(b)
#         num[b]+=1
#     def dfs(x):
#         global vis,edge,num
#         vis[x]=1
#         for i in edge[x]:
#             if vis[i]==0:
#                 num[i]-=1
#                 if num[i]==0:dfs(i)
#         return 0
#     for i in range(1,n+1):
#         if vis[i]==0 and num[i]==0:
#             dfs(i)
#     cur+=(('Yes'if sum(vis)!=n else'No')+'\n')
# print(cur)

# cur=''
# for _ in range(int(input())):
#     try:n,m=list(map(int,input().split()))
#     except:break
#     vis,edge,num=[0]*(n+1),[[]for _ in range(n+1)],[0]*(n+1)
#     for _ in range(m):
#         a,b=list(map(int,input().split()))
#         edge[a].append(b)
#         num[b]+=1
#     def dfs(x):
#         global vis,edge,num
#         vis[x]=1
#         for i in edge[x]:
#             if vis[i]==0:
#                 num[i]-=1
#                 if num[i]==0:dfs(i)
#         return 0
#     for i in range(1,n+1):
#         if vis[i]==0 and num[i]==0:
#             dfs(i)
#     cur+=(('Yes'if sum(vis)!=n else'No')+'\n')
# print(cur)
# from collections import deque
# cur=''
# for _ in range(int(input())):
#     try:n,m=list(map(int,input().split()))
#     except:break
#     vis,edge,num=[0]*(n+1),[[]for _ in range(n+1)],[0]*(n+1)
#     for _ in range(m):
#         a,b=list(map(int,input().split()))
#         edge[a].append(b)
#         num[b]+=1
#     q=deque()
#     for i in range(1,n+1):
#         if num[i]==0:
#             vis[i]=1
#             q.append(i)
#     while q:
#         x=q.popleft()
#         for i in edge[x]:
#             if vis[i]==0:
#                 num[i]-=1
#                 if num[i]==0:
#                     q.append(i)
#                     vis[i]=1
#     cur+=(('Yes'if sum(vis)!=n else'No')+'\n')
# print(cur)

from collections import defaultdict
def dfs(node,color):
    color[node]=1
    for neighbor in graph[node]:
        if color[neighbor]==1:
            return True
        if color[neighbor]==0 and dfs(neighbor,color):
            return True
    color[node]=2
    return False
T=int(input())
for _ in range(T):
    N,M=map(int,input().split())
    graph=defaultdict(list)
    for _ in range(M):
        x,y=map(int,input().split())
        graph[x].append(y)
    color=[0]*(N+1)
    is_cyclic=False
    for node in range(1,N+1):
        if color[node]==0:
            if dfs(node,color):
                is_cyclic=True
                break
    print("Yes"if is_cyclic else "No")