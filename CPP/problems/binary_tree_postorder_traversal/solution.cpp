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
    vector<int> postorderTraversal(TreeNode* curr) {
        vector<int> postorder;
        if(curr==NULL)  return postorder;
        stack<TreeNode*> s1,s2;
        s1.push(curr);
        while(!s1.empty()){
            curr=s1.top();
            s2.push(curr);
            s1.pop();
            if(curr->left)  s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
        while(!s2.empty()){
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};