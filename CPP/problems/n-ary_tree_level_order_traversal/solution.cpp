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
    vector<vector<int>> res;
    void helper(Node* root, int level) {
        if (!root) return;
        if (level == res.size()) res.push_back({});
        res[level].push_back(root->val);
        for (auto child : root->children)
            helper(child, level+1);
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        helper(root, 0);
        return res;
    }
};