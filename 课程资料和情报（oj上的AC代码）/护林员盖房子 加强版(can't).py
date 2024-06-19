m,n=map(int,input().split())
bd=[list(map(int,input().split()))for _ in range(m)]
a=[[0]*n for _ in range(m-1)]+[[int(not bd[-1][i])for i in range(n)]]
for i in range(m-2,-1,-1):
    for j in range(n):
        if bd[i][j]==0:a[i][j]=a[i+1][j]+1
ans=0
for i in range(m):
    st1,st2,st=[n]*n,[-1]*n,[]
    for j in range(n):
        while st and a[i][j]<a[i][st[-1]]:st1[st.pop()]=j
        st.append(j)
    for j in range(n-1,-1,-1):
        while st and a[i][j]<a[i][st[-1]]:st2[st.pop()]=j
        st.append(j)
    for j in range(n):
        if a[i][j]:ans=max(ans,a[i][j]*(st1[j]-st2[j]-1))
print(ans)