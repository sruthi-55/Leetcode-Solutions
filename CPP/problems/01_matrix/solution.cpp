class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis,vector<vector<int>>& res){
        int m=mat.size(),n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++) {
	        for(int j=0;j<n;j++) {
	            if(mat[i][j] == 0) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                vis[i][j] = 0; 
	            }
	        }
	    }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int step=q.front().second;

            q.pop();
            res[r][c]=step;
            int nrow[]={-1,0,1,0};
            int ncol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+nrow[i];
                int nc=c+ncol[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && mat[nr][nc]==1 && !vis[nr][nc]){
                    q.push({{nr,nc},step+1});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> res=mat;
        bfs(mat,vis,res);   
        return res;
    }
};