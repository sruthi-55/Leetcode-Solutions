class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m=grid.size(),n=grid[0].size();
        vis[r][c]=1;
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+nrow[i];
            int nc=c+ncol[i];
            if(nr>=0 &&  nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    void bfs(int sr,int sc,vector<vector<int>>& mat,vector<vector<int>>& vis){
        int m=mat.size(),n=mat[0].size();
        vis[sr][sc]=1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dR[]={-1,0,1,0};
            int dC[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=r+dR[i];
                int ncol=c+dC[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n &&
                !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        bfs(i,j,grid,vis);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j])
                    count++;
            }
        }
        return count;
    }
};