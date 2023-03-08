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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre,post,0,pre.size()-1,0,post.size()-1);
    }

    int findElement(vector<int> post, int element){
        return find(post.begin(), post.end(), element) - post.begin();
    }
    TreeNode* helper(vector<int>& pre, vector<int>& post,int preS,int preE,int poS,int poE){
        if(preE<preS)    return NULL;
        TreeNode *root=new TreeNode(pre[preS]);
        if(preS==preE)  return root;
        int poI=findElement(post, pre[preS+1]);
        int beforeR=poI-poS+1;
        root->left=helper(pre,post,preS+1,preS+beforeR,poS,poI);
        root->right=helper(pre,post,preS+beforeR+1,preE,poI+1,poE-1);
        return root;
    }
};

