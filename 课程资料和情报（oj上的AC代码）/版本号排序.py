from functools import cmp_to_key as ctk
def cmp(l1,l2):
    lis1,lis2,c1,c2=list(map(int,l1.split('.'))),list(map(int,l2.split("."))),0,0
    for i in range(min(len(lis1),len(lis2))+1):
        if i==len(lis1):return -1
        if i==len(lis2):return 1
        if lis1[i]==lis2[i]:continue
        elif lis1[i]<lis2[i]:return -1
        else:return 1
print('\n'.join(sorted([input()for i in range(int(input()))])))

    
