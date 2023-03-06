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
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> res;
        stack<TreeNode*> s1,s2;
        while(r1||r2||!s1.empty()||!s2.empty()){
            while(r1){
                s1.push(r1);r1=r1->left;
            }  
            while(r2){
                s2.push(r2);r2=r2->left;
            } 
            if(s2.empty() || (!s1.empty() && s1.top()->val<=s2.top()->val)){
                r1=s1.top();
                s1.pop();
                res.push_back(r1->val);
                r1=r1->right;
            }
            else{
                r2=s2.top();s2.pop();
                res.push_back(r2->val);
                r2=r2->right;
            }
        }
        return res;
    }
};