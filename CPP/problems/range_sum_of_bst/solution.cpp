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
    int ans;
    int rangeSumBST(TreeNode* root, int l, int h) {
        ans=0;
        dfs(root,l,h);
        return ans;
    }
    void dfs(TreeNode *root,int l,int h){
        if(root)   {
            if(root->val<=h && root->val>=l)    ans+=root->val;
            if(l<root->val) dfs(root->left,l,h);
            if(h>root->val)    dfs(root->right,l,h);
        }
    }
};