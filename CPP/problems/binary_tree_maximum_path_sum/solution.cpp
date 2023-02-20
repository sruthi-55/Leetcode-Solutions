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
    int sum(TreeNode* curr,int &maxs){
        if(!curr)   return 0;
        int ls=max(0,sum(curr->left,maxs));
        int rs=max(0,sum(curr->right,maxs));
        int val=curr->val;
        maxs=max(maxs,val+ls+rs);
        return max(ls,rs)+val;
    }
    int maxPathSum(TreeNode* root) {
        int maxs=INT_MIN;
        sum(root,maxs);
        return maxs;
    }
};