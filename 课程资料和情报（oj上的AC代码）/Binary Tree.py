ans=""
for i in range(int(input())):
    ans+='Scenario #'+str(i+1)+":\n"
    a,b=list(map(int,input().split()))
    c1,c2=0,0
    while a>1 or b>1:
        if a>b:
            c1+=((a-1)//b)
            a%=b
        else:
            c2+=((b-1)//a)
            b%=a
    ans+=str(c1)+" "+str(c2)+"\n\n"
print(ans)