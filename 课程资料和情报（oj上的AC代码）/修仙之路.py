# 经过了的点，不需要在两层for循环中进入了，这个点可以优化
def check(x,y,r,c):
    return (x>=0 and x<r and y>=0 and y<c)
def dfs(board,x,y,r,c):
    dx,dy,ans=[0,0,1,-1],[1,-1,0,0],1
    for i in range(4):
        xx,yy=x+dx[i],y+dy[i]
        if check(xx,yy,r,c) and board[xx][yy]>board[x][y]:
            ans=max(ans,1+dfs(board,xx,yy,r,c))
    return ans

r,c=list(map(int,input().split()))
board=[list(map(int,input().split())) for i in range(r)]
ans=0
for i in range(r):
    for j in range(c):
        ans=max(ans,dfs(board,i,j,r,c))
        
print(ans)
    