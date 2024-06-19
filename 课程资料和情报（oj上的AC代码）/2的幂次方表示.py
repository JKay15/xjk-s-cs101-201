def power(n):
    if n==1:return "2(0)"
    if n==2: return "2"
    ans,cnt=1,0
    while ans<n:
        ans*=2
        cnt+=1
    if ans==n:return "2("+power(cnt)+")"
    else:
        ans//=2
        if ans==2:return "2"+"+"+power(n-ans)
        else: return "2("+power(cnt-1)+")"+"+"+power(n-ans)

print(power(int(input())))
    