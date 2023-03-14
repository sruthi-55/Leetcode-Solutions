class Solution {
public:
    void dfs(vector<vector<int>>& img,int r,int c,int scolor,int color,vector<vector<int>>& ans){
        int m=img.size(),n=img[0].size();
        ans[r][c]=color;
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+nrow[i];
            int nc=c+ncol[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && img[nr][nc]==scolor && ans[nr][nc]!=color){
                dfs(img,nr,nc,scolor,color,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int m=img.size();
        int n=img[0].size();
        int scolor=img[sr][sc];
        vector<vector<int>> ans = img;
        dfs(img,sr,sc,scolor,color,ans);
        return ans;
    }
};