# 思路对了，但是好像有点繁琐
from collections import deque
for _ in range(int(input())):
    lis,k=input().split()
    lis,k=list(map(int,lis)),int(k)
    st,ans=deque(),[-1 for _ in range(len(lis))]
    for i in range(len(lis)):
        while len(st) and lis[st[-1]]>lis[i]:
            ans[st[-1]]=i
            st.pop()
        st.append(i)
    ok=[1 for _ in range(len(lis))]
    for i in range(len(lis)):
        if ok[i] and ans[i]!=-1 and ans[i]-i<=k:
            cur=i
            while cur<ans[i]:
                ok[cur]=0
                cur+=1
                k-=1
    cur=-1
    while k:
        ok[cur]=0
        cur-=1
        k-=1
    print(''.join([str(lis[i])for i in range(len(lis)) if ok[i]]))