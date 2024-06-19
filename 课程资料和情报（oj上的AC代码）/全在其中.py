ans=""
while True:
    try:a,b=input().split()
    except:break
    l1,l2=len(a),len(b)
    if l1>l2:ans+="No\n"
    else:
        j=0
        for i in range(l2):
            if j==l1:break
            if b[i]==a[j]:
                j+=1
        ans+="Yes\n"if j==l1 else "No\n"
print(ans)