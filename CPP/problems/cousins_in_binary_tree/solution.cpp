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
    int x_par,y_par,x_dep,y_dep;
    void helper(TreeNode* root, int x, int y,int dep,int par){
        if(!root)   return;
        if(root->val==x){
            x_dep=dep;
            x_par=par;
            return;
        }
        if(root->val==y){
            y_dep=dep;
            y_par=par;
            return;
        }
        helper(root->left,x,y,dep+1,root->val);
        helper(root->right,x,y,dep+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)   return true;
        helper(root,x,y,0,0);
        if(x_par!=y_par && x_dep==y_dep) return true;
        return false;
    }
};