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
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(root){
            if(root->val>k) root->left = deleteNode(root->left,k);
            else if(root->val<k)    root->right = deleteNode(root->right,k);
            else{
                if(!root->left && !root->right) return NULL;
                if(!root->left) return root->right;
                if(!root->right)   return root->left;

                TreeNode *temp=root->right;
                while(temp->left != NULL) temp = temp->left; 
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
        }   
        return root;
    }
};