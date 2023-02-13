class Solution {
public:
    int f(int m, int n, vector<vector<int>>& grid){
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int left=0,up=0;
                    if(j-1>=0) left=dp[i][j-1];
                    if(i-1>=0) up=dp[i-1][j];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
		int uniquePathsWithObstacles(vector<vector<int>>& grid) {
            int m=grid.size(), n=grid[0].size();
            return f(m,n,grid); 
    }
};