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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root= buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder,int preS,int preE,int inS,int inE,unordered_map<int,int> &m){
        if(preS>preE || inS>inE)    return NULL;
        TreeNode *root=new TreeNode(preorder[preS]);
        int inR=m[root->val];
        int beforeR=inR-inS;
        root->left=buildTree(preorder,inorder,preS+1,preS+beforeR,inS,inR-1,m);
        root->right=buildTree(preorder,inorder,preS+beforeR+1,preE,inR+1,inE,m);
        return root;
    }
};