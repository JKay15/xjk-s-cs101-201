lc,rc=[],[]
def build(s1,s2):
    if not len(s1):return -1
    if len(s1)==1:return ord(s1[0])-ord('A')
    root=ord(s1[0])-ord('A')
    l=s2.index(s1[0])
    lc[root]=build(s1[1:1+l],s2[:l])
    rc[root]=build(s1[1+l:],s2[l+1:])
    return root
def dfs(root):
    ans=""
    if lc[root]!=-1:ans+=dfs(lc[root])
    if rc[root]!=-1:ans+=dfs(rc[root])
    ans+=chr(root+ord('A'))
    return ans
while True:
    try:s1,s2=input(),input()
    except:break
    lc,rc=[-1 for i in range(26)],[-1 for i in range(26)]
    print(dfs(build(s1,s2)))