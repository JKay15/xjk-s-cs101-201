# 超时
# from collections import deque
# n=int(input())
# il=[[int(i)for i in input()]for _ in range(n)]
# def dfs(x,y,n):
#     dx,dy=[-1,1,0,0],[0,0,1,-1]
#     for i in range(4):
#         xx,yy=x+dx[i],y+dy[i]
#         if 0<=xx<n and 0<=yy<n and il[xx][yy]==1:
#             il[xx][yy]=2
#             dfs(xx,yy,n)
# ok=0
# for i in range(n):
#     for j in range(n):
#         if il[i][j]:
#             il[i][j]=2
#             dfs(i,j,n)
#             ok=1
#             break
#     if ok:break
# ans=10000000
# for i in range(n-1,-1,-1):
#     for j in range(n-1,-1,-1):
#         dx,dy=[-1,1,0,0],[0,0,1,-1]
#         if il[i][j]==1:
#             ok=0
#             for k in range(4):
#                 xx,yy=i+dx[k],j+dy[k]
#                 if 0<=xx<n and 0<=yy<n and (il[xx][yy]==0):
#                     ok=1
#                     break
#             if not ok:continue
#             vis=[[0 for _ in range(n)]for _ in range(n)]
#             queue=deque([(i,j,0)])
#             while len(queue):
#                 x,y,t=queue.popleft()
#                 for k in range(4):
#                     xx,yy=x+dx[k],y+dy[k]
#                     if 0<=xx<n and 0<=yy<n and (not vis[xx][yy]) :
#                         if il[xx][yy]==2:
#                             ans=min(ans,t)
#                             ok=0
#                             break
#                         vis[xx][yy]=1
#                         queue.append((xx,yy,t+1))
#                 if not ok:break
# print(ans)
class Solution:
    def shortestBridge(self, grid):
        n = len(grid)
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v != 1:
                    continue
                q = []
                def dfs(x, y):
                    grid[x][y] = -1
                    q.append((x, y))
                    for nx, ny in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                        if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                            dfs(nx, ny)
                dfs(i, j)

                step = 0
                while True:
                    tmp = q
                    q = []
                    for x, y in tmp:
                        for nx, ny in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                            if 0 <= nx < n and 0 <= ny < n:
                                if grid[nx][ny] == 1:
                                    return step
                                if grid[nx][ny] == 0:
                                    grid[nx][ny] = -1
                                    q.append((nx, ny))
                    step += 1
n=int(input())
il=[[int(i)for i in input()]for _ in range(n)]
a=Solution()
print(a.shortestBridge(il))