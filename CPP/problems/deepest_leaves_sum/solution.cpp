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
    int sumT=0,maxDepth=0;
    int deepestLeavesSum(TreeNode* root,int depth=0) {
        if(!root)   return 0;
        deepestLeavesSum(root->left,depth+1);
        deepestLeavesSum(root->right,depth+1);
        if(depth>maxDepth){
            maxDepth=depth;
            sumT=root->val;
        }
        else if(depth==maxDepth)    sumT+=root->val;
        return sumT;
    }
};