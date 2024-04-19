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
class Solution{
    public:
    void inorder(TreeNode* root, vector<int> &t){
        if(root){
            inorder(root->left, t);
            t.push_back(root->val);
            inorder(root->right, t);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> t;
        inorder(root, t);
        int i=0; int j= t.size()-1;
        while(i<j){
            int temp= t[i] + t[j];
            if(temp == k)
                return true;
            if(temp<k)
                i++;
            else
                j--;
        }
        return false;
    }
};