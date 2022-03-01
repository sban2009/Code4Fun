"""
Given a tree, print its
1. maximum width (i.e. maximum nodes at any particular level)
2. level order traversal (BFS or level by level traversal)
3. spiral/zigzag traversal (similar to level order)
"""
from collections import deque


class node:
    def __init__(self, data) -> None:
        self.data = data
        self.left = None
        self.right = None


def max_width(root):
    # returns maximum width (max. #nodes at a level) in BT (5,15,7=> 3 nodes)
    if not root:
        return 0
    q = deque()
    q.append(root)
    maxsize = 0
    while q:
        count = len(q)
        maxsize = max(count, maxsize)
        while count:
            x = q.popleft()
            # print(x.data, q)
            count -= 1
            if x.left is not None:
                q.append(x.left)
            if x.right is not None:
                q.append(x.right)
    return maxsize


def level_order(root):
    # returns list of list containing nodes of BT, level-wise (3,9,20,5,15,7)
    if not root:
        return 0
    q = deque()
    q.append(root)
    result = []
    while q:
        count = len(q)
        result.append([i.data for i in q])
        while count:
            x = q.popleft()
            # print(x.data, q)
            count -= 1
            if x.left is not None:
                q.append(x.left)
            if x.right is not None:
                q.append(x.right)
    return result


def spiral(root):
    # returns zigzag/spiral order of nodes (3,20,9,5,15,7)
    if not root:
        return 0
    q = deque()
    q.append(root)
    level = -1  # *changed code from level_order
    result = []
    while q:
        count = len(q)
        level += 1  # *changed code from level_order
        if level % 2 == 0:  # *changed code from level_order
            result.append([i.data for i in q])
        else:
            result.append([i.data for i in reversed(q)])
        while count:
            x = q.popleft()
            # print(x.data, q)
            count -= 1
            if x.left is not None:
                q.append(x.left)
            if x.right is not None:
                q.append(x.right)
    return result


def main():
    """
    binary tree:
        3
       / \
      9   20
     /    / \
    5    15  7
    """
    root = node(3)
    root.left = node(9)
    root.right = node(20)
    root.left.left = node(5)
    root.right.left = node(15)
    root.right.right = node(7)

    print(max_width(root))
    print(level_order(root))
    print(spiral(root))


if __name__ == "__main__":
    main()
