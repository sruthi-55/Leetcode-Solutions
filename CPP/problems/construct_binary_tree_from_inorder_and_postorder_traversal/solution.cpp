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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode *root=helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,m);
        return root;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int inS,int inE,int poS,int poE,unordered_map<int,int> &m){
        if(inE<inS || poE<poS)  return NULL;
        TreeNode *root=new TreeNode(postorder[poE]);
        int inR=m[root->val];
        int beforeR=inR-inS;
        root->left=helper(inorder,postorder,inS,inR-1,poS,poS+beforeR-1,m);
        root->right=helper(inorder,postorder,inR+1,inE,poS+beforeR,poE-1,m);
        return root;
    }

};