t1,t2=list(map(int,input().split()))
while t1!=t2 and min(t1,t2)>=1:
    if t1>t2:t1=t1//2
    else:t2=t2//2
print(t1)