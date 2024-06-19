from collections import defaultdict as d
dic=d(int)
for _ in range(n:=int(input())):dic[input()]+=1
for i in sorted(list(dic.items()),key=lambda x:x[0]):print(i[0],f'{(100*i[1]/n):.4f}%')