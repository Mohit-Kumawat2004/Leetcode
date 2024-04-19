/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, int &i, int k){
        if(root == NULL){
            return -1;
        }

        //LEFT
        int left = solve(root->left,i,k);
        if(left != -1){
            return left;
        }

        //NODE
        i++;
        if(i==k){
            return root->val;
        }

        //RIGHT
        return solve(root -> right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans = solve(root,i,k);
        return ans;
    }
}; //k smallest