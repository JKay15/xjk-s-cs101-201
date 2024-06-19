lc,rc=[-1 for i in range(26)],[-1 for i in range(26)]
def build(s1,s2):
    global lc,rc
    if not len(s1):return -1
    root=ord(s2[-1])-ord('A')
    l=s1.index(s2[-1])
    lc[root]=build(s1[:l],s2[:l])
    rc[root]=build(s1[l+1:],s2[l:-1])
    return root
def pre(i):
    return chr(i+ord('A'))+(pre(lc[i]) if lc[i]!=-1 else "")+(pre(rc[i]) if rc[i]!=-1 else "")
print(pre(build(input(),input())))

    