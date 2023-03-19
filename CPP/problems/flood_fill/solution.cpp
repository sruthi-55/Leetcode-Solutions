class Solution {
public:
    void dfs(vector<vector<int>>& img,int r,int c,int scolor,int color,vector<vector<int>>& res){
        int m=img.size(),n=img[0].size();
        res[r][c]=color;
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+nrow[i];
            int nc=c+ncol[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && img[nr][nc]==scolor && res[nr][nc]!=color){
                dfs(img,nr,nc,scolor,color,res);
            }
        }
    }
    void bfs(vector<vector<int>>& img,int sr,int sc,int color,int newColor,vector<vector<int>>& res){
        int m=res.size(),n=res[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        res[sr][sc]=newColor;
        int dR[]={-1,0,1,0};
        int dC[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dR[i];
                int ncol=c+dC[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n &&
                res[nrow][ncol]!=newColor && img[nrow][ncol]==color){
                    q.push({nrow,ncol});
                    res[nrow][ncol]=newColor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int m=img.size();
        int n=img[0].size();
        int scolor=img[sr][sc];
        vector<vector<int>> res = img;
        bfs(img,sr,sc,scolor,color,res);
        return res;
    }
};