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
    TreeNode *ans;
    int deepest=0;
    int helper(TreeNode* root,int depth){
        if(!root)   return depth-1;
        deepest=max(deepest,depth);
        int left=helper(root->left,depth+1);
        int right=helper(root->right,depth+1);
        if(left==deepest && right==deepest)    ans=root;
        return max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};