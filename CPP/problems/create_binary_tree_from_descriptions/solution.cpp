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
    TreeNode* createBinaryTree(vector<vector<int>>& vec) {
        unordered_map<int,TreeNode*> m;
        unordered_set<int> s;
        for(auto i:vec){
            if(m.count(i[0])==0){
                TreeNode* par=new TreeNode(i[0]);
                m[i[0]]=par;
            }
            if(m.count(i[1])==0){
                TreeNode* child=new TreeNode(i[1]);
                m[i[1]]=child;
            }
            if(i[2])    m[i[0]]->left=m[i[1]];
            else    m[i[0]]->right=m[i[1]];
            s.insert(i[1]);
        }
        TreeNode* root = NULL;
        for(auto i: vec){
            if(!s.count(i[0])){
                root = m[i[0]]; 
                break;
            }
        }
        return root;
    }
};