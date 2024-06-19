from itertools import permutations
N,dic,words,ordered=int(input()),set(),[input()for i in range(4)],permutations([0,1,2,3])
def dfs(i,order,tmp):
    if i>=4:
        dic.add(tmp)
        return
    for j in range(6):
        cur=tmp+words[order[i]][j]
        dic.add(cur)
        dfs(i+1,order,cur)
for x in ordered:dfs(0,x,"")
for _ in range(N):
    t=input()
    if t in dic:print("YES")
    else: print("NO")
## 更好的做法
from collections import defaultdict
from itertools import permutations

a = defaultdict(int)
b = defaultdict(int)
c = defaultdict(int)
d = defaultdict(int)
n = int(input())

for i in input():
    a[i] += 1
for i in input():
    b[i] += 1
for i in input():
    c[i] += 1
for i in input():
    d[i] += 1

dicts = [a, b, c, d]

def check(word):
    for perm in permutations(dicts, len(word)):
        for i, d in enumerate(perm):
            if word[i] not in d:
                break
        else:
            return 'YES'
    else:
        return 'NO'

for _ in range(n):
    word = input()
    print(check(word))