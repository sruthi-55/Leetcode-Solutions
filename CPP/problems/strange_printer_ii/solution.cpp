class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        //dependancy graph
        vector<unordered_set<int>> dep(61);
        for (int k=1; k<=60; k++) {
            int minX = m, minY = n, maxX = -1, maxY = -1;
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (grid[x][y] == k) {
                        minX = min(x, minX);
                        minY = min(y, minY);
                        maxX = max(x, maxX);
                        maxY = max(y, maxY);
                    }
                }
            }
            for (int i=minX;i<=maxX;i++) {
                for (int j=minY;j<=maxY;j++) {
                   if (grid[i][j] != k)
                       dep[k].insert(grid[i][j]);
                }
            }
        }
        vector<int> vis(61, 0);
        for (int i = 1; i <= 60; ++i) {
            if (!vis[i] && hasCircle(i, dep, vis)) return false;
        }
        return true;
    }
    //topological sort checking
    //checking cycle in dependancy graph
private:
    bool hasCircle(int i,vector<unordered_set<int>>& dep, vector<int>& vis) {
        vis[i] = 1;
        for (int d : dep[i]) {
            if (vis[d] == 2) continue;
            if (vis[d] == 1) return true;
            if (hasCircle(d, dep, vis)) return true;
        }
        vis[i] = 2;
        return false;
    }
};