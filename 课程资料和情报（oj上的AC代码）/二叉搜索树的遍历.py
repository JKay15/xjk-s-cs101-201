from bisect import bisect_left as bl
def dfs(s):
    if len(s)<=1:return s
    p=bl(s[1:],s[0])
    return dfs(s[1:p+1])+dfs(s[p+1:])+[s[0]] 
input()
print(' '.join(map(str,dfs(list(map(int,input().split()))))))