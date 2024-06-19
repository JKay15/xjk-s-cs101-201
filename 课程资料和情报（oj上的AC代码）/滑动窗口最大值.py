n,k=list(map(int,input().split()))
num,queue,ans=list(map(int,input().split())),[],[]
for i in range(n):
    while len(queue)and num[i]>=num[queue[-1]]:queue.pop()
    queue.append(i)
    if i>=k-1:
        while i-queue[0]>=k:queue.pop(0)
        ans.append(str(num[queue[0]]))
print(' '.join(ans))



    
