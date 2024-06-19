from collections import deque
edge,ind,n,res=[],[],0,''
def topo():
    global edge,ind
    ind1=ind.copy()
    seq,tmp,ok='',deque(),1
    for i in range(n):
        if ind1[i]==0:tmp.append(i)
    if len(tmp)>1:ok=0
    while tmp:
        cur=tmp.popleft()
        for i in edge[cur]:
            ind1[i]-=1
            if ind1[i]==0:tmp.append(i)
        if len(tmp)>1:ok=0
        seq+=chr(cur+ord('A'))
    if len(seq)<n:return -1
    if ok:return seq
    return 0
while 1:
    n,m=map(int,input().split())
    if n==0:break
    edge,ind,ans=[[]for _ in range(n)],[0]*n,''
    for i in range(m):
        x,y=map(lambda x:ord(x)-ord('A'),input().split('<'))
        edge[x].append(y)
        ind[y]+=1
        if ans:continue
        cur=topo()
        if cur==-1:ans='Inconsistency found after '+str(i+1)+' relations.'
        elif cur:ans='Sorted sequence determined after '+str(i+1)+" relations: "+cur+'.'
    res+=("Sorted sequence cannot be determined.\n"if ans==''else ans+'\n')
print(res)
    
                
        