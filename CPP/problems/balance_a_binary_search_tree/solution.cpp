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
    vector<int> sorted;
    void inorder(TreeNode* root){
        if(!root)   return;
        inorder(root->left);
        sorted.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* sortedToBST(int l,int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(sorted[mid]);
        root->left=sortedToBST(l,mid-1);
        root->right=sortedToBST(mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortedToBST(0,sorted.size()-1);
    }
};