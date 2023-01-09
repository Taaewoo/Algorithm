# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import copy

class Solution:
    ans = []
    cur = []

    def dfs(self, tree, targetSum, acc):
        if tree.left == None and tree.right == None:
            if targetSum == acc:
                self.ans.append(copy.deepcopy(self.cur))
            return

        if tree.left != None:
            self.cur.append(tree.left.val)
            self.dfs(tree.left, targetSum, acc+tree.left.val)
            self.cur.pop()
        if tree.right != None:
            self.cur.append(tree.right.val)
            self.dfs(tree.right, targetSum, acc+tree.right.val)
            self.cur.pop()

        return

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        self.ans = []
        self.cur = []

        if root == None:
            return self.ans

        self.cur.append(root.val)
        self.dfs(root, targetSum, root.val)
        
        return self.ans
