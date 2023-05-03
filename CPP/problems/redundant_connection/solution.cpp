class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<bool> &vis,int par=-1){
        if(vis[i])  return true;
        vis[i]=true;
        for(auto nei:graph[i]){
            if(nei!=par && dfs(nei,graph,vis,i))  return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1);
        for(auto &ai: edges){
            fill(begin(vis), end(vis), false);  
            graph[ai[0]].push_back(ai[1]);
            graph[ai[1]].push_back(ai[0]);
            if(dfs(ai[0],graph,vis)) return ai;
        }
        return {};
    }
};