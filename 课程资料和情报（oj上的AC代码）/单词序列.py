from collections import deque
s,e=input().split()
dic,vis=set(input().split()),set()
q=deque([(s,1)])
vis.add(s)
while q:
    cur,n=q.popleft()
    for i in range(len(cur)):
        for j in range(26):
            k=cur[:i]+chr(ord('a')+j)+cur[i+1:]
            if k==e:
                print(n+1)
                exit()
            if k not in vis and k in dic:
                vis.add(k)
                q.append((k,n+1))
print(0)