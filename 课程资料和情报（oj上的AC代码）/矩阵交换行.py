# 难点在于如何在python中实现c++的cout<< setw(4)<< num;
tmp=[list(map(int,input().split()))for _ in range(5)]
m=[]
for i in tmp:
    ans=''
    for j in i:ans+=f"{j:4}"
    m.append(ans)
a,b=map(int,input().split())
if 0<=a<5 and 0<=b<5:
    l=m[a]
    m[a]=m[b]
    m[b]=l
    print('\n'.join(m))
else:print('error')