from collections import defaultdict
def post(root):
    global lc,rc,src
    a=""
    if lc[root]>=0:a+=post(lc[root])
    if rc[root]>=0:a+=post(rc[root])
    a+=src[root]
    return a
def mid(root):
    global lc,rc,src
    a=""
    if lc[root]>=0:a+=mid(lc[root])
    a+=src[root]
    if rc[root]>=0:a+=mid(rc[root])
    return a
ans=""
for i in range(int(input())):
    src,lc,rc,dic="",[-1 for i in range(15)],[-1 for i in range(15)],defaultdict()
    while True:
        s=input()
        if s=='0':break
        if s[-1]=='*':
            lc[dic[len(s)-2]]=-2
            continue
        src+=s[-1]
        l,l1=len(s),len(src)
        dic[l-1]=l1-1
        if l-1>0:
            if lc[dic[l-2]]==-1:lc[dic[l-2]]=l1-1
            else:rc[dic[l-2]]=l1-1
    ans+=src+"\n"+post(0)+"\n"+mid(0)+"\n\n"
print(ans)