class Solution {
public:
    void dfs(int i,int n,vector<vector<int>> &adj,vector<int> &vis){
        if(vis[i])  return;
        vis[i]=1;
        for(auto nei:adj[i]){
            dfs(nei,n,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components=0;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(connections.size()< n-1)  return -1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,n,adj,vis);
                components++;
            }
        }
        return components-1;
    }
};