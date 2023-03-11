class Solution {
public:
    void dfs(int cur,vector<int> &vis,vector<vector<int>>& edge){
        // vis[cur]=1;
        int n=edge[0].size();
        for(int i=0; i<n; i++){
            if(!vis[i] && edge[cur][i]){
                vis[i]=1;
                dfs(i,vis,edge);
            }
        }
    }
    void bfs(int cur,vector<int> &vis,vector<vector<int>>& edge){
        int n=edge[0].size();
        queue<int> q;
        q.push(cur);
        vis[cur]=1;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(int j=0; j<n; j++){
                if(!vis[j] && edge[i][j]){
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& edge) {
        int n=edge.size();
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,edge);
                c++;
            }
        }
        return c;
    }
};