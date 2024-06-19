for i in range(int(input())):
    stack,queue,error=[],[],0
    for j in range(int(input())):
        a=input()
        if not error:
            if a[1]=='u':
                stack.append(a.split()[1])
                queue.append(a.split()[1])
            else:
                if len(stack)==0:
                    error=1
                    continue
                else:
                    stack=stack[:-1]
                    queue=queue[1:]
    if error:print("error\nerror")
    else:
        print(" ".join(queue)," ".join(stack),sep='\n')