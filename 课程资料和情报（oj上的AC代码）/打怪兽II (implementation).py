n,w=list(map(int,input().split()))
p,q=list(map(int,input().split()))
ans=[]
for i in range(n):
    x,y=list(map(int,input().split()))
    if x<=p+q:ans.append(y)
ans.sort()
num=0
for i in ans:
    if w>i:
        num+=1
        w-=i
    else:
        num+=(1 if w==i else 0)
        break
print(num)

