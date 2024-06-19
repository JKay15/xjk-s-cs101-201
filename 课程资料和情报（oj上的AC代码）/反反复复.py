n=int(input())
a=[[] for i in range(100)]
str=input()
for i in range(len(str)):
    if (i//n)%2==0:a[i//n].append(str[i])
    else:a[i//n].insert(0,str[i])
for i in range(n):
    for j in range(len(str)//n):print(a[j][i],end="")
