s=input()
def dfs():
    global s
    if not len(s):return
    root,s,a1,a2=s[0],s[1:],'',''
    if len(s)and s[0]!='.':
        l=dfs()
        a1,a2=l[0],l[1]
    else:s=s[1:]
    a1+=root
    if len(s)and s[0]!='.':
        r=dfs()
        a1,a2=a1+r[0],a2+r[1]
    else:s=s[1:]
    return (a1,a2+root)
print('\n'.join(dfs()))
        