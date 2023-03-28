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
    int ans=0;
    int sumEvenGrandparent(TreeNode* root,int p=1,int gp=1) {
        if(!root)   return 0;
        int left=sumEvenGrandparent(root->left,root->val,p);
        int right=sumEvenGrandparent(root->right,root->val,p);
        if(gp%2==0) return left+right+root->val;
        else return left+right;
    }
};