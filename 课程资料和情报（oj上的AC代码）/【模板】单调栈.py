from collections import deque
n,lis,st=int(input()),list(map(int,input().split())),deque()
ans=[0 for _ in range(n)]
for i in range(n):
    while len(st) and lis[st[-1]]<lis[i]:
        ans[st[-1]]=i+1
        st.pop()
    st.append(i)
print(' '.join(map(str,ans)))