def dfs(n):
    if n==1:return [' /\\ ','/__\\']
    A,tmp=dfs(n-1),' '*2**(n-1)
    return [tmp+i+tmp for i in A]+[i+i for i in A]
while True:
    n=int(input())
    if not n:break
    print("\n".join(dfs(n))+'\n')