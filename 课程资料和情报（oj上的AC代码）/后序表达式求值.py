def pro(s):
    num,ope=[],[]
    for i in s:
        if i=='+':
            t1,t2=num[-1],num[-2]
            num=num[:-2]+[t1+t2,]
        elif i=='-':
            t1,t2=num[-1],num[-2]
            num=num[:-2]+[t2-t1,]
        elif i=='*':
            t1,t2=num[-1],num[-2]
            num=num[:-2]+[t2*t1,]
        elif i=='/':
            t1,t2=num[-1],num[-2]
            num=num[:-2]+[t2/t1,]
        else:
            num.append(float(i))
    return num[0]
            
for i in range(int(input())):print("%.2f"%pro(input().split()))