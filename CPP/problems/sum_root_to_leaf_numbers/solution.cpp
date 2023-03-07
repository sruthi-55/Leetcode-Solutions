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
    int helper(TreeNode *root,int s){
        if(!root)   return 0;
        s=s*10+root->val;
        if(!root->left && !root->right) return s;
        int l=helper(root->left,s);
        int r=helper(root->right,s);
        return l+r;
        
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        if(!root)   return res;
        res=helper(root,0);
        return res;
    }
};