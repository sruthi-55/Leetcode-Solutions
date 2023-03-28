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
    int rangeSumBST(TreeNode* root, int l, int h) {
        if(!root)   return 0;
        int ans=0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            if(node->val>=l && node->val<=h){
                ans+=node->val;
            } 
            if(node->left && node->val>=l)  s.push(node->left);
            if(node->right && node->val<=h) s.push(node->right);
        }
        return ans;
    }
    
};