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
    vector<int> inorder;
    void dfs(TreeNode* curr){
        if(curr==NULL)  return;
        dfs(curr->left);
        inorder.push_back(curr->val);
        dfs(curr->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return inorder;
    }
};