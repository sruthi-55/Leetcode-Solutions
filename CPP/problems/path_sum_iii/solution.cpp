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
    int helper(TreeNode* root,long long prev, long long s){
        if(!root)   return 0;
        long long cur=prev+(long long)root->val;
        return (cur==s)+ helper(root->left,cur,s)+ 
        helper(root->right,cur,s);
    }
    int pathSum(TreeNode* root, int targetS) {
        if(!root)   return 0;
        int ans=0;
        ans=helper(root,0,targetS)+ pathSum(root->left,targetS)+
        pathSum(root->right,targetS);
        return ans;
    }
};