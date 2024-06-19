ans=""
for t in range(int(input())):
    n,m=list(map(int,input().split()))
    f=[i for i in range(2*n+2)]
    def find_x(i):
        global f
        if i==f[i]:return i
        f[i]=find_x(f[i])
        return f[i]
    def union(i,j):
        fx,fy=find_x(i),find_x(j)
        f[fy]=fx
    ok=0
    for _ in range(m):
        x,y=list(map(int,input().split()))
        fx,fy,fy1=find_x(x),find_x(y),find_x(y+n)
        if fx!=fy1:
            if fx!=fy:
                union(x,y+n)
                union(x+n,y)
            else:ok=1
    ans+="Scenario #"+str(t+1)+":\n"+("Suspicious"if ok else"No suspicious")+" bugs found!\n\n"
print(ans)