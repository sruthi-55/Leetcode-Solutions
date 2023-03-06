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
    TreeNode* searchBST(TreeNode* root, int k) {
        if(!root)   return root;
        TreeNode *node=new TreeNode();
        if(root->val>k) node=searchBST(root->left,k);
        else if(root->val<k)    node=searchBST(root->right,k);
        else    node=root;
        return node;
    }
};