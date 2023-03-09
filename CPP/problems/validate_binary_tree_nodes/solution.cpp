class Solution {
public:
    bool dfs(int root,vector<int>& leftChild, vector<int>& rightChild){
        queue<int>q;
        q.push(root);
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            if(leftChild[node] != -1) q.push(leftChild[node]);
            if(rightChild[node] != -1) q.push(rightChild[node]);
        }
        return count == leftChild.size();
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n,0);
        int count=0;
        //traversing and updating inDegree of every node
        //other than root all should have indegree=0or1 (i.e !>1)
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                inDegree[leftChild[i]]++;
                if(inDegree[leftChild[i]]>1)    return false;
                count++;
            }
            if(rightChild[i]!=-1){
                inDegree[rightChild[i]]++;
                if(inDegree[rightChild[i]]>1)    return false;
                count++;
            }
        }
        if(count!=n-1)  return false;

        int root=-1;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                if(root==-1)    root=i;
                else    return false;
            }
        }
        // return true;

        //every node sould be traversed exactly once
        //visited nodes count should be n
        //traverse from root to check if all nodes are visited exactly once;
        return dfs(root,leftChild,rightChild);
    }
};