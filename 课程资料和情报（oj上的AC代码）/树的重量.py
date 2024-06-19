import math
k,n=list(map(int,input().split()))
tree,tag,ans=[0 for i in range(2**k)],[0 for i in range(2**k)],""
def down(tar,x):
    global tree
    if tar==1:return tag[tar] if x else 0
    return (tag[tar] if x else 0)+down(int(tar/2),1)
def num(tar,sum):
    global tree
    tree[tar]+=sum
    if tar==1:return
    return num(int(tar/2),sum)
for _ in range(n):
    a=list(map(int,input().split()))
    if a[0]==1:
        num(a[1],(2**(k-int(math.log2(a[1])))-1)*a[2])
        tag[a[1]]+=a[2]
    else:ans+=str(tree[a[1]]+(2**(k-int(math.log2(a[1])))-1)*down(a[1],0))+"\n"
print(ans)

