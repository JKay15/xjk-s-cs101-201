from functools import lru_cache
@lru_cache
def dfs(n):
    if n<=1:return 1
    ans=0
    for i in range(n):ans+=dfs(i)*dfs(n-i-1)
    return ans
print(dfs(int(input())))