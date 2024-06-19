from collections import deque
op=['FILL','DROP','POUR']
a,b,c=list(map(int,input().split()))
vis=[[0 for _ in range(b+1)]for _ in range(a+1)]
q,vis[0][0]=deque([(0,0,'')]),1
ans='impossible'
while len(q):
    x,y,opr=q.popleft()
    if x==c or y==c:
        ans=opr
        break
    for i in range(3):
        for j in range(1,3):
            if op[i][0]=='F':(xx,yy)=(a,y) if j==1 else (x,b)
            elif op[i][0]=='D':(xx,yy)=(0,y) if j==1 else (x,0)
            else:(xx,yy)=(max(0,x-b+y),min(y+x,b)) if j==1 else (min(x+y,a),max(0,y-a+x))
            if not vis[xx][yy]:
                vis[xx][yy]=1
                q.append((xx,yy,opr+str(3*i+j)))
if ans[0]=='i':print(ans)
else:
    print(len(ans))
    for i in ans:
        x,y=int(i)//3,int(i)%3
        print(op[x]+'('+str(y)+((','+str(1 if y==2 else 2))if x==2 else '')+')')