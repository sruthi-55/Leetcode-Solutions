/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node* node,vector<int> &ans){
        if(!node)   return;
        ans.push_back(node->val);
        for(int i=0;i<node->children.size();i++)
            helper(node->children[i],ans);
    }
    vector<int> preorder(Node* root) {
        if(!root)   return {};
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};