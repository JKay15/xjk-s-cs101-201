str,cur,ans=input(),"",""
for i in str:
    cur+=i
    if int(bytes(cur,"utf-8"),2)%5==0:ans+="1"
    else:ans+="0"
    
print(ans)
        