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
    vector<int> postorder(Node* root) {
        if(!root)   return {};
        vector<int> ans;
        stack<pair<Node*,int>> s;
        s.push({root,0});
        while(!s.empty()){
            auto &[node,index]=s.top();
            if(index==node->children.size()){
                ans.push_back(node->val);
                s.pop();
            }
            else{
                s.push({node->children[index++],0});
            }
        }
        return ans;
    }
};