# l m r  & l r m
lc,rc=[],[]
def build(s1,s2):
    if not len(s1):return -1
    if len(s1)==1:return ord(s1[0])-ord("A")
    global lc,rc
    root=ord(s2[-1])-ord('A')
    l=s1.index(s2[-1])
    lc[root]=build(s1[:l],s2[:l])
    rc[root]=build(s1[l+1:],s2[l:-1])
    return root

for i in range(int(input())):
    lc,rc=[-1 for i in range(26)],[-1 for i in range(26)]
    str1,str2=input(),input()
    root=build(str1,str2)
    queue,ans=[root,],""
    while len(queue):
        cur=queue[0]
        ans+=chr(cur+ord('A'))if cur!=-1 else ""
        queue=queue[1:]
        if lc[cur]!=-1:queue.append(lc[cur])
        if rc[cur]!=-1:queue.append(rc[cur])
    print(ans)

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(inorder, postorder):
    if not inorder:
        return None

    root_val = postorder[-1]
    root = TreeNode(root_val)

    root_index = inorder.index(root_val)

    root.left = build_tree(inorder[:root_index], postorder[:root_index])
    root.right = build_tree(inorder[root_index + 1:], postorder[root_index:-1])

    return root

def level_order_traversal(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        level_size = len(queue)
        level_values = []

        for _ in range(level_size):
            node = queue.pop(0)
            level_values.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.extend(level_values)

    return result

n = int(input().strip())
for _ in range(n):
    inorder = input().strip()
    postorder = input().strip()
    root = build_tree(inorder, postorder)
    print(''.join(level_order_traversal(root)))
