n,m=list(map(int,input().split()))
lis,na={},""
for i in range(n):
    a,ans,num=input().split(),0,0
    for i in range(1,len(a),2):
        if 60<=float(a[i])<=100:ans+=(4-3*(100-float(a[i]))**2/1600)*int(a[i+1])
        num+=int(a[i+1])
    lis[a[0]]=ans/num
lis=sorted(list(lis.items()),key=lambda x:x[1],reverse=True)
for i in range(m):na+=lis[i][0]+" "
print(na)