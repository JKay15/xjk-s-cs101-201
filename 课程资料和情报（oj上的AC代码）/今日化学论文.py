s='['+input()+']'
w=0
def dfs():
    global s,w
    cur,mul='',0
    while w<len(s):
        w+=1
        if s[w-1]=='[':cur+=dfs()
        elif '0'<=s[w-1]<='9':mul=mul*10+int(s[w-1])
        elif s[w-1]==']':return cur*(mul if mul else 1)
        else:cur+=s[w-1]
    return cur*(mul if mul else 1)
print(dfs())
        