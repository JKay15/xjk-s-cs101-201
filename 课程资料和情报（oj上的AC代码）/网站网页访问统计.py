from datetime import datetime as d
from collections import defaultdict
ans,s=defaultdict(float),'%H:%M:%S'
for i in range(int(input())):
    a,b,c=input().split()
    ans[a]+=(d.strptime(c,s)-d.strptime(b,s)).total_seconds()
print(sorted(list(ans.items()),key=lambda x:x[1])[-1][0])