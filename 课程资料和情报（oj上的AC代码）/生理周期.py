# 看错题了，p、e、i不是周期，周期是在题目一开始就给出了的
def gcd(x,y):
    if x<y:return gcd(y,x)
    if y==0:return x
    return gcd(y,x%y)

maxn,cnt=21152,1
while True:
    try:p,e,i,d=list(map(int,input().split()))
    except:break
    if not p or not e or not i:
        print("Case ",cnt,": the next triple peak occurs in ",maxn-d," days.",sep="")
        cnt+=1
        continue
    lcd1=p*e//gcd(p,e)
    ans=lcd1*i//gcd(lcd1,i)
    print(ans)