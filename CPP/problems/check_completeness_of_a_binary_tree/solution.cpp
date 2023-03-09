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
    int count(TreeNode *root){
        if(!root)   return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool dfs(TreeNode *cur,int ind,int n){
        if(!cur)    return true;
        if(ind>=n)  return false;
        bool l=dfs(cur->left,2*ind+1,n);
        bool r=dfs(cur->right,2*ind+2,n);
        return l&&r;
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root)   return true;
        return dfs(root,0,count(root));
    }
};