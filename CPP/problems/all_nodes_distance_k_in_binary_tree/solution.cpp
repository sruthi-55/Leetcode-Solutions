/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParents(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &m,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> m;
        makeParents(root,m,target);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty()){
            int size=q.size();
            if(distance++==k) break;
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left && visited[temp->left]==false){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && visited[temp->right]==false){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(m[temp] && visited[m[temp]]==false){
                    q.push(m[temp]);
                    visited[m[temp]]=true;
                }
            }
        }
        while(!q.empty()){
            TreeNode *node=q.front();q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};