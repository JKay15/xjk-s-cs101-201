n,lis,mmax=int(input()),[-1]+list(map(int,input().split()))+[-1],[]
for i in range(1,n+1):
    if lis[i-1]<lis[i]>=lis[i+1] or lis[i-1]<=lis[i]>lis[i+1]:mmax.append(i)
mm=[]
mmax=[0]+mmax+[0]
for i in range(1,len(mmax)-1):
    if lis[mmax[i-1]]<lis[mmax[i]]>=lis[mmax[i+1]] or lis[mmax[i-1]]<=lis[mmax[i]]>lis[mmax[i+1]]:mm.append(i)
i,j,ans=1,0,0
while i<len(mmax)-2:
    if i!=mm[j]:
        cur=min(lis[mmax[i]],lis[mmax[i+1]])
        for k in range(mmax[i]+1,mmax[i+1]):ans+=max(0,cur-lis[k])
        i+=1
    else:
        if j!=len(mm)-1:
            cur=min(lis[mmax[i]],lis[mmax[mm[j+1]]])
            for k in range(mmax[i]+1,mmax[mm[j+1]]):ans+=max(0,cur-lis[k])
            i=mm[j+1]
            j+=1
        else:
            cur=min(lis[mmax[i]],lis[mmax[i+1]])
            for k in range(mmax[i]+1,mmax[i+1]):ans+=max(0,cur-lis[k])
            i+=1
print(ans)
            

        
    
