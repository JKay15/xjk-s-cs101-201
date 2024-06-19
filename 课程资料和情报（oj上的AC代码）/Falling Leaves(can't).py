ans,tt,v,l,r='','',[],[],[]
def build(x,s,cnt):
    global v,l,r
    if s<v[x]:
        if l[x]!=-1:build(l[x],s,cnt)
        else:l[x],v[cnt]=cnt,s
    else:
        if r[x]!=-1:build(r[x],s,cnt)
        else:r[x],v[cnt]=cnt,s
def pre(x):return v[x]+(pre(l[x])if l[x]!=-1 else '')+(pre(r[x])if r[x]!=-1 else '')
while 1:
    s=input()
    if s in ['*','$']:
        L=len(tt)
        v,l,r=[''for _ in range(L)],[-1 for _ in range(L)],[-1 for _ in range(L)]
        v[0]=tt[-1]
        for x,i in enumerate(tt[-2::-1]):build(0,i,x+1)
        ans+=pre(0)+'\n'
        tt=''
        if s=='$':break
    else:tt+=s
print(ans)