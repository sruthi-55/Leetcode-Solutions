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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        //v,l,val
        map<int,map<int,multiset<int>>> m;
        //node,v,l
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode *temp=p.first;
            int v=p.second.first;
            int l=p.second.second;
            m[v][l].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{v-1,l+1}});
            }
            if(temp->right){
                q.push({temp->right,{v+1,l+1}});
            }
        }
        //should keep nodes vertical wise
        for(auto ele:m){
            vector<int> v;
            for(auto lval:ele.second){
                v.insert(v.end(),lval.second.begin(),lval.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};