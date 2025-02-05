s=input()
cur,cur1,l=0,len(s),len(s)
while cur<l and s[cur].isalpha():cur+=1
if cur<l and s[l-1].isalpha():
    cur1-=1
    while s[cur1].isalpha():cur1-=1
str=s[cur:cur1+1]
def dfs(l,r):
    global str
    num,cur,ans=1,l+1,[""]
    while num>=0 and cur<=r:
        if str[cur].isalpha():
            ans[-1]+=str[cur]
        elif str[cur]=='(':
            num+=1
            tmp=""
            if num>1:
                tmp,cur=dfs(cur,r)
                ans[-1]+=tmp
                num-=1
                continue
            ans[-1]+=tmp
        else:
            num-=1
        if not num:ans.append("")
        cur+=1
    ans=''.join([i[::-1]for i in ans])
    return ans,cur-1
            
if str:
    l=len(str)
    print(s[:cur]+dfs(0,l-1)[0]+s[cur1+1:])
    
else: print(s)

## 以上的做法是很不明智的，需要完全地使用栈来做才好，递归反而是加大了思维难度
def reverse_dialogue(script):
    stack = []
    dialogue = ''

    for char in script:
        if char == '(':
            stack.append(dialogue)
            dialogue = ''
        elif char == ')':
            dialogue = stack.pop() + dialogue[::-1]
        else:
            dialogue += char

    return dialogue

# 测试样例
script = input()
result = reverse_dialogue(script)
print(result)