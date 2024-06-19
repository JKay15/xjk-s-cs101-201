q,p,ans,a1=[[]for i in range(9)],[[]for i in range(4)],"",""
_,lis=input(),input().split()
for i in lis:q[ord(i[1])-ord('1')].append(i)
for n,i in enumerate(q):
    ans+="Queue"+str(n+1)+":"+' '.join(i)+"\n"
    for j in i:p[ord(j[0])-ord('A')].append(j)
for n,i in enumerate(p):
    ans+="Queue"+chr(n+ord('A'))+":"+' '.join(i)+'\n'
    a1+=' '.join(i)+' '
print(ans,a1,sep='')


