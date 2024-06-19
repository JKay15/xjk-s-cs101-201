N=int(input())
for a in range(2,N+1):
    for b in range(2,a):
        for c in range(b,a):
            for d in range(c,a):
                if b**3+c**3+d**3==a**3:
                    print("Cube = ",a,", Triple = (",b,",",c,",",d,")",sep="")
