from functools import cmp_to_key
def comp(x,y):
    if x%2:
        if y%2:return y-x
        return -1
    if not y%2:return x-y
    return 1 
print(" ".join(map(str,sorted(list(map(int,input().split())),key=cmp_to_key(comp)))))