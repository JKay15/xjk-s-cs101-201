class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
def insert(node, value):
    if node is None:
        return Node(value)
    if value < node.value:
        node.left = insert(node.left, value)
    elif value > node.value:
        node.right = insert(node.right, value)
    return node
def traversal(root):
    queue = [root]
    traversal = []
    while queue:
        node = queue.pop(0)
        traversal.append(node.value)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    return traversal
numbers = list(map(int, input().strip().split()))
numbers = list(dict.fromkeys(numbers))  
root = None
for number in numbers:root = insert(root, number)
traversal1 = traversal(root)
print(' '.join(map(str, traversal1)))