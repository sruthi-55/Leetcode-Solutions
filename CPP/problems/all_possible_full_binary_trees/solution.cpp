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
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n<1 || n%2==0)   return {};
        if(dp[n].size()!=0) return dp[n];
        vector<TreeNode*> ans;
        if(n==1){
            ans.push_back(new TreeNode(0));
        }
        else{
            for(int i=1;i<n;i+=2){
                vector<TreeNode*> left=allPossibleFBT(i);
                vector<TreeNode*> right=allPossibleFBT(n-i-1);
                for(int i=0;i<left.size();i++){
                    for(int j=0;j<right.size();j++){
                        TreeNode* root=new TreeNode(0);
                        root->left=left[i];
                        root->right=right[j];
                        ans.push_back(root);
                    }
                }
            }
        }
        dp[n]=ans;
        return ans;
    }
};