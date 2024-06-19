s=input()
while s!='.':
    k,ok=len(s),1
    for i in range(1,k//2):
        if k%i==0:
            if s==s[:i]*(k//i):
                print(k//i)
                ok=0
                break
    if ok:print(1)
    s=input()