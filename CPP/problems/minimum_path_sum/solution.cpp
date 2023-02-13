class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> prev(m,0);
        
        for(int i=0;i<n;i++){
            vector<int> cur(m,0);
            for(int j=0;j<m;j++){
                if(i==0&&j==0)  cur[j]=mat[i][j];
                else{
                    int left=mat[i][j];
                    if(j>0) left+=cur[j-1];
                    else    left+=1e9;

                    int up=mat[i][j];
                    if(i>0) up+=prev[j];
                    else    up+=1e9;
                    cur[j]=min(left,up);
                }   
            }
            prev=cur;
        }
        return prev[m-1];
        }
};