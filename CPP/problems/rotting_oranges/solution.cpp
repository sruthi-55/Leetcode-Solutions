class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        int cntFresh=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)   cntFresh++;
            }
        }
        int tt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tt=max(tt,t);
            q.pop();
            int xc[]={-1,0,1,0};
            int yc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=r+xc[i];
                int ncol=c+yc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                    vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                        q.push({{nrow,ncol},t+1});
                        vis[nrow][ncol]=2;
                        count++;
                }
            }
        }
        if(count!=cntFresh) return -1;
        return tt;
    }
};