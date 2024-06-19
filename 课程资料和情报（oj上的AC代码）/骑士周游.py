dx,dy,vis,n,ans=[-1,1,-1,1,2,2,-2,-2],[2,2,-2,-2,1,-1,1,-1],[],0,0
def avai(x,y):
    global dx,dy,vis,n
    a=0
    for i in range(8):
        xx,yy=x+dx[i],y+dy[i]
        if (0<=xx<n and 0<=yy<n)and (not vis[xx][yy]):a+=1
    return a
def dfs(x,y,cnt):
    global dx,dy,vis,n,ans
    if cnt==n*n or ans:
        ans+=1
        return
    lis=sorted([(x+dx[i],y+dy[i])for i in range(8) if (0<=x+dx[i]<n and 0<=y+dy[i]<n)and (not vis[x+dx[i]][y+dy[i]])],key=lambda x:avai(x[0],x[1]))
    for i,j in lis:
        vis[i][j]=1
        dfs(i,j,cnt+1)
        if ans:return
        vis[i][j]=0
n=int(input())
x,y=list(map(int,input().split()))
vis=[[0 for _ in range(n)]for _ in range(n)]
vis[x][y]=1
dfs(x,y,1)
print('success'if ans else 'fail')