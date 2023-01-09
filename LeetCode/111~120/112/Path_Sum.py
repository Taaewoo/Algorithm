# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, tree, targetSum, acc):
        if tree.left == None and tree.right == None:
            if targetSum == acc+tree.val:
                return True
            else:
                return False

        res1, res2 = False, False

        if tree.left != None:
            res1 = self.dfs(tree.left, targetSum, acc+tree.val)
        
        if tree.right != None:
            res2 = self.dfs(tree.right, targetSum, acc+tree.val)

        return (res1 or res2)

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root == None:
            return False
        return self.dfs(root,targetSum,0)
