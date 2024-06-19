t=int(input())
ans,num='',1
while t:
    ans+="Test case #"+str(num)+'\n'
    num+=1
    s=input()
    f=[0]*(t+1)
    f[0],f[1]=-1,0
    for i in range(2,t+1):
        cur=f[i-1]
        while cur>=0 and s[i-1]!=s[cur]:cur=f[cur]
        f[i]=cur+1
    cur=''
    for i in range(2,t+1):
        for l in range(1,f[i]+1):
            if i%l==0:
                ok=1
                for j in range(i//l-1):
                    now=i-j*l
                    while now>0 and f[now]>l:now=f[now]
                    if f[now]<l:
                        ok=0
                        break
                if ok:
                    cur+=str(i)+' '+str(i//l)+'\n'
                    break
    ans+=cur+'\n'
    t=int(input())
print(ans)