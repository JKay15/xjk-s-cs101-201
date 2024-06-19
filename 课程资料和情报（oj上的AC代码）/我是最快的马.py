from collections import deque
sx,sy=map(int,input().split())
ex,ey=map(int,input().split())
p=set([tuple(map(int,input().split()))for _ in range(int(input()))])
q,dx,dy,vis=deque([[sx,sy,'('+str(sx)+','+str(sy)+')']]),[-2,-2,-1,1,2,2,1,-1],[1,-1,-2,-2,-1,1,2,2],set([(sx,sy)])
ans,cur=0,''
while q:
    tmp=deque()
    while q:
        x,y,path=q.popleft()
        wx,wy=[-1,0,1,0],[0,-1,0,1]
        if x==ex and y==ey:
            ans+=1
            if ans==1:cur=path
        for i in range(8):
            xx,yy,x1,y1=x+dx[i],y+dy[i],x+wx[i//2],y+wy[i//2]
            if (xx,yy)not in vis and (x1,y1)not in p:tmp.append([xx,yy,path+'-'+'('+str(xx)+','+str(yy)+')'])
    if ans:break
    q=tmp
print(cur if ans==1 else ans)