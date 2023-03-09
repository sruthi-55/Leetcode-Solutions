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
    int maxi=INT_MIN;
    int dfs(TreeNode *root,int maxi,int mini){
        if(!root)   return maxi-mini;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        return max(dfs(root->left,maxi,mini),dfs(root->right,maxi,mini));

    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)   return 0;
        return dfs(root,root->val,root->val);
    }
};