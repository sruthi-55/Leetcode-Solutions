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
    int ans=0,count=0;
    void helper(TreeNode* root){
        if(root->left)   helper(root->left);
        count--;
        if(count==0){
            ans=root->val;
            return ;
        }
        if(root->right) helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        count=k;
        helper(root);
        return ans;
    }
};