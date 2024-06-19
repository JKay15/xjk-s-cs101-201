for _ in range(int(input())):
    n=int(input())
    lis=list(map(int,input().split()))
    k,t_stick,t_squ,nei=lis[0],2*n*(n+1)-len(lis)+1,0,2*n+1
    ans=t_stick
    stick,square,exi=[[]for _ in range(65)],[[]for _ in range(65)],[0 for _ in range(65)]
    def h():
        global exi,t_squ,square,stick
        tmp=exi.copy()
        res=0
        for i in range(1,t_squ+1):
            if not tmp[i]:
                res+=1
                tmp[i]-=len(square[i])
                for j in square[i]:
                    for l in stick[j]:tmp[l]-=1
        return res             
    def dfs(d,maxd):
        global t_squ,exi,ans,square,stick
        if d+h()>=maxd:return 0
        tmp=1
        while exi[tmp]<0 and tmp<=t_squ:tmp+=1
        if tmp>t_squ:
            ans=min(ans,d)
            return 1
        for sti in square[tmp]:
            for j in stick[sti]:exi[j]-=1
            if dfs(d+1,maxd):return 1
            for j in stick[sti]:exi[j]+=1
        return 0
    for sz in range(1,n+1):
        i=1
        while int((i-1)/nei)+sz<=n:
            for j in range(i,i+n-sz+1):
                t_squ+=1
                for l in range(j,j+sz):
                    square[t_squ].extend([l,l+sz*nei])
                    stick[l].append(t_squ)
                    stick[l+sz*nei].append(t_squ)
                l=j+n
                while int((l-j-sz)/nei)<sz:
                    square[t_squ].extend([l,l+sz])
                    stick[l].append(t_squ)
                    stick[l+sz].append(t_squ)
                    l+=nei
            i+=nei
    for t in lis[1:]:
        for j in stick[t]:exi[j]-=1
    for maxd in range(1,t_stick+1):
        if dfs(0,maxd):break
    print(ans)



            

