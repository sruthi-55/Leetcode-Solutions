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
    void rec(TreeNode* curr,int l,vector<int> &v){
        if(!curr)   return;
        if(v.size()==l) v.push_back(curr->val);
        rec(curr->right,l+1,v);
        rec(curr->left,l+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rec(root, 0, v);
        return v;
    }
};