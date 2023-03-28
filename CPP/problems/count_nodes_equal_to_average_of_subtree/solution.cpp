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
    int count(TreeNode *curr){
        if(!curr)   return 0;
        return 1+count(curr->left)+count(curr->right);
    }
    int sum(TreeNode *curr){
        if(!curr)   return 0;
        return curr->val+sum(curr->left)+sum(curr->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)   return 0;
        return (sum(root)/count(root)==root->val) + 
                averageOfSubtree(root->left) + 
                averageOfSubtree(root->right);
    }
};