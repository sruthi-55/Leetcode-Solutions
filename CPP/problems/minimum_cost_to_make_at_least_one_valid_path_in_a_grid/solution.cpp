class Solution {
public:
    int del[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int cost=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        dfs(grid,0,0,dp,q,cost);
        while(!q.empty()){
            cost++;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();  q.pop();
                for(int j=0;j<4;j++)
                    dfs(grid,p.first+del[j][0],p.second+del[j][1],dp,q,cost);
            }
        }
        return dp[m-1][n-1];
    }
    void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& dp,
        queue<pair<int,int>>& q,int cost){
        int m=grid.size(),n=grid[0].size();
        if(r<0 ||  c<0 || c>=n || r>=m || dp[r][c] != INT_MAX)  return;
        dp[r][c]=cost;
        q.push(make_pair(r,c));
        int nextDel=grid[r][c]-1;
        dfs(grid,r+del[nextDel][0],c+del[nextDel][1],dp,q,cost);
    }
};