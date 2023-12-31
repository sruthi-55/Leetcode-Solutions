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
    int res=0;
    int findTilt(TreeNode* root) {
        findSum(root);
        return res;
    }
    int findSum(TreeNode* root) {
        if(!root)   return 0;
        int ls=findSum(root->left);
        int rs=findSum(root->right);
        res+=abs(ls-rs);
        return ls+rs+root->val;
    }
};