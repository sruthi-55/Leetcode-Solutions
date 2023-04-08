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
    int maxDepth(Node* root) {
        if(!root)   return 0;
        vector<int> temp(root->children.size());
        int maxi=0;
        for(int i=0;i<root->children.size();i++){
            temp[i]=maxDepth(root->children[i]);
            maxi=max(maxi,temp[i]);
        }
        return 1+maxi;
    }
};