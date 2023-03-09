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
    TreeNode *leftMost,*rightMost;
    void levelorder(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(i==0)    leftMost=temp;
                if(i==size-1)   rightMost=temp;
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
    }
    TreeNode* lca(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root)   return NULL;
        if(root==p || root==q)  return root;
        TreeNode *left=lca(root->left,p,q);
        TreeNode *right=lca(root->right,p,q);
    
        if(left==NULL)  return right;
        else if(right==NULL)    return left;
        else    return root;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        levelorder(root);
        return lca(root,leftMost,rightMost);
    }
};