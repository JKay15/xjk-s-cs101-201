def dfs(n):
    if n==0:return '*'
    tmp=dfs(n-1)
    return tmp+'-'*3**(n-1)+tmp
print(dfs(int(input())))