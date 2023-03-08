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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder,int par_val=INT_MAX) {
        if(i==preorder.size() || preorder[i]>par_val)   return NULL;
        int cur_val=preorder[i++];
        TreeNode *temp=new TreeNode(cur_val);
        temp->left=bstFromPreorder(preorder,cur_val);
        temp->right=bstFromPreorder(preorder,par_val);
        return temp;
    }
};