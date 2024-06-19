def check(x):
    for i in range(len(x)):
        j=len(x)-i-1
        if i>j:break
        if x[i]!=x[j]:return 0
    return 1

while True:
    try: a=input()
    except:break
    print("YES" if check(a) else "NO")
    