class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int m=grid.size(),n=grid[0].size();
        vis[r][c]=1;
        
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+nrow[i];
            int nc=c+ncol[i];
            if(nr>=0 &&  nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]=='O'){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    void bfs(int sr,int sc,vector<vector<char>> &mat,vector<vector<int>> &vis){
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
                !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
    }
    void solve(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(!vis[i][j] && grid[i][j]=='O'){
                        bfs(i,j,grid,vis);
                    }
                }
            }
        }
        //convert unvisited O's to x
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!vis[i][j] && grid[i][j]=='O')
                    grid[i][j]='X';
            }
        }
        // return grid;
    }
};