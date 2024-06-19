m,l=[],[]
n=int(input())
for i in range(n):
    mi,li=list(map(int,input().split()))
    m.append(mi)
    l.append(li)

def check(i):
    if i==0:
        if m[i]+l[i]<m[1]:return 1
        return 0
    elif i==n-1:
        if m[i]-l[i]>m[n-2]:return 1
        return 0
    else:
        if m[i]+l[i]<m[i+1] and m[i]-l[i]>m[i-1]:return 1
        return 0
        
cur=-0x7777777
ans = 0
for i in range(n):
    if check(i):
        if m[i]-l[i]>cur:
            cur=m[i]+l[i]
            ans+=1
print(ans)