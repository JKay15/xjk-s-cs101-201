lc,rc,w=[],[],-1
def build(s):
    global lc,rc,w
    if s[w].islower():
        w-=1
        return w+1
    cur=w
    stack=[cur]
    w-=1
    while s[w].isupper():
        rc[stack[-1]]=w
        stack.append(w)
        w-=1
    rc[stack[-1]]=w
    w-=1
    for i in stack[::-1]:lc[i]=build(s)
    return stack[0]
        
for i in range(int(input())):
    s=input()
    lc,rc,w=[-1 for i in range(len(s))],[-1 for i in range(len(s))],len(s)-1
    root=build(s)
    ans,queue,l="",[root],1
    while l:
        for i in range(l):
            ans+=s[queue[i]]
            if lc[queue[i]]!=-1:queue.append(lc[queue[i]])
            if rc[queue[i]]!=-1:queue.append(rc[queue[i]])
        queue=queue[l:]
        l=len(queue)
    print(ans[::-1])

    
    