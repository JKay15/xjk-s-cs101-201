dict={}
for i in range(int(input())):
    a,b,c=input().split()
    b,c=int(b),int(c)
    n=32*b+c
    if n not in dict:
        dict[n]=[a]
    else: dict[n].append(a)

for i in sorted(dict,key=lambda x:(x//32,x%32)):
    if len(dict[i])>1:print(i//32,i%32," ".join(dict[i]))
    
        
