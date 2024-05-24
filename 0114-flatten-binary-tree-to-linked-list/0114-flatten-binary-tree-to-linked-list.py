# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None: return 
        def dfs(root):
            # Base case
            if root.left is None and root.right is None:
                return root
            
            # Recurrence relation
            left_node = None
            right_node = None
            
            # If the left node is not NULL
            if root.left:
                # Get the last child based on preorder-traverse
                left_node = dfs(root.left)

            # If right node is not NULL
            if root.right:
                # Get the last child  based on preorder-traverse
                right_node = dfs(root.right)

            # Induction
            if left_node:
                left_node.right = root.right
                root.right = root.left
                left_node.left = None 
                root.left = None

            # Return the last node of the left sub-tree
            if right_node:
                return right_node
            return left_node
        dfs(root)