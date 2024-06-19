def gcd(x,y):
    if y==0:return x
    if x<y:return gcd(y,x)
    return gcd(y,x%y)

t1,t2,t3,t4=list(map(int,input().split()))
g=gcd(t2,t4)
t1,t3,d=t1*(t4//g),t3*(t2//g),t2*t4//g
f,ans=t1+t3,gcd(t1+t3,d)
f1,d1=f//ans,d//ans
if f1==0:
    print(0)
    exit()
if d1<0:f1,d1=-f1,-d1
print(str(f1)+"/"+str(d1))


