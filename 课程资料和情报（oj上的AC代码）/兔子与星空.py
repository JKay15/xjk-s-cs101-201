# n,f,e=int(input()),[i for i in range(26)],[]
# for _ in range(n-1):
#     tmp=input().split()
#     for i in range(2,len(tmp),2):
#         cu=[ord(tmp[0])-ord('A'),ord(tmp[i])-ord('A'),int(tmp[i+1])]
#         e.extend([cu,[cu[1],cu[0],cu[2]]])
# def find(i):
#     global f
#     if f[i]==i:return i
#     f[i]=find(f[i])
#     return f[i]
# def union(i,j):
#     global f
#     f1,f2=find(i),find(j)
#     f[f1]=f2
# e.sort(key=lambda x:x[2])
# tmp,ans=n,0
# for i in e:
#     f1,f2=find(i[0]),find(i[1])
#     if f1!=f2:
#         tmp-=1
#         ans+=i[2]
#         union(i[0],i[1])
#         if tmp==1:break
# print(ans)