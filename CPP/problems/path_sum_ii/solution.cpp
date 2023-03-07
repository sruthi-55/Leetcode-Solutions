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
    void helper(vector<vector<int>> &res,vector<int> path,TreeNode *root,int sum){
        // if(!root)   return;
        path.push_back(root->val);
        if(!root->left && !root->right && sum==root->val){
            res.push_back(path);
        } 
        if(root->left)  helper(res,path,root->left,sum-root->val);
        if(root->right)  helper(res,path,root->right,sum-root->val);
        // path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<int> path;
        if(!root)   return res;
        helper(res,path,root,target);
        return res;
    }
};