class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> hasIncoming(n,false);
        for(vector<int> &edge:edges){
            hasIncoming[edge[1]]=true;
        }
        for(int i=0;i<n;i++){
            if(!hasIncoming[i])
                ans.push_back(i);
        }
        return ans;
    }
};