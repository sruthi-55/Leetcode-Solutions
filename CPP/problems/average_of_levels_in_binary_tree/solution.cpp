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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root)   return {};
        queue<TreeNode*> q;
        q.push(root);
        res.push_back(root->val);
        while(!q.empty()){
            int size=q.size();
            double sum=0,n=0;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    n++;sum+=node->left->val;
                }  
                if(node->right){
                    q.push(node->right);
                    n++;sum+=node->right->val;
                } 
            }
            if(n)   res.push_back(sum/n);
        }
        return res;
    }
};