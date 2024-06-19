dic,s,ans={},input(),""
while s!='#':
    dic[s]=len(dic)
    s=input()
s=input()
while s!='#':
    if s in dic:ans+=s+' is correct\n'
    else:
        ans+=s+':'
        cur=set()
        for i in [chr(ord('a')+x)for x in range(26)]:
            if i+s in dic:cur.add(i+s)
        for i in range(len(s)):
            tmp=s[:i]+s[i+1:]
            if tmp in dic:cur.add(tmp)
            for j in [chr(ord('a')+x)for x in range(26)]:
                tmp=s[:i]+j+s[i+1:]
                if tmp in dic:cur.add(tmp)
                tmp=s[:i+1]+j+s[i+1:]
                if tmp in dic:cur.add(tmp)
        ans+=' '+' '.join(sorted(list(cur),key=lambda x:dic[x]))+'\n'
    s=input()
print(ans)

    
    
    