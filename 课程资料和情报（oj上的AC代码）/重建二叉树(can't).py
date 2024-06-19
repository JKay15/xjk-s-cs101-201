##迷惑。。。
# ans=""
# cnt=0
# def build(pre,mid):
#     global cnt,ans
#     cnt+=1
#     print("time: ",cnt,end=" :")
#     print(pre,mid,";Current answer: ",ans)
#     if len(pre)==0:return ""
#     if len(pre)==1:return pre[0]
#     w=mid.index(pre[0])
#     if not w:
#         ans+=build(pre[1:],mid[w+1:])
#         return pre[0]
#     w1=pre.index(mid[w-1])
#     if w1==len(pre)-1:return pre[0]
#     ans+=build(pre[1:w1+1],mid[:w])
#     ans+=build(pre[w1+1:],mid[w+1:])
#     # print(build(pre[1:w1+1],mid[:w]),end='')
#     # print(build(pre[w1+1:],mid[w+1:]),end='')
#     return pre[0]

# while True:
#     try:
#         a,b=input().split()
#     except:
#         break
#     ans+=build(a,b)
#     # print(ans)
lc,rc,src=[],[],""
def build(pre,mid):
    if not len(pre):return -1
    global lc,rc,src
    src+=pre[0]
    root=len(src)-1
    l=mid.index(src[-1])
    lc[root]=build(pre[1:l+1],mid[0:l])
    rc[root]=build(pre[l+1:],mid[l+1:])
    return root
def post(root):
    global lc,rc,src
    ans=""
    if lc[root]!=-1:ans+=post(lc[root])
    if rc[root]!=-1:ans+=post(rc[root])
    ans+=src[root]
    return ans
while True:
    try:s1,s2=input().split()
    except:break
    lc,rc,src=[-1 for i in range(26)],[-1 for i in range(26)],""
    root=build(s1,s2)
    print(post(root))
    
    
    
    

    