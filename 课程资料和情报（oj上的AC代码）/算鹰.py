bd,vis,dx,dy,ans=[input()for _ in range(10)],[[0 for _ in range(10)]for _ in range(10)],[1,-1,0,0],[0,0,-1,1],0
def dfs(x,y):
    global vis,dx,dy,bd
    vis[x][y]=1
    for i in range(4):
        xx,yy=x+dx[i],y+dy[i]
        if 0<=xx<10 and 0<=yy<10 and not vis[xx][yy] and bd[xx][yy]=='.':dfs(xx,yy)
for i in range(10):
    for j in range(10):
        if bd[i][j]=='.' and not vis[i][j]:
            dfs(i,j)
            ans+=1
print(ans)
            
    
            