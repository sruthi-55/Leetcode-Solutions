class Solution {
public:
    int dfs(int i,vector<vector<int>> &adj,vector<int> &vis){
        int count=0;
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[abs(it)]){
                if(it>0)    count+=1+dfs(abs(it),adj,vis);
                else    count+=dfs(abs(it),adj,vis);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<int> vis(n,0);
        return dfs(0,adj,vis);
    }
};