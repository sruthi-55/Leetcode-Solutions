class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int> prev(n,0), cur(n,0);
        for(int j=0; j<n; j++){
            prev[j] = arr[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = arr[i][j] + prev[j];
                int d1= arr[i][j];
                if(j-1>=0) d1 += prev[j-1];
                else d1 += 1e9;
                
                int d2 = arr[i][j];
                if(j+1<n) d2 += prev[j+1];
                else d2 += 1e9;
                cur[j] = min(up, min(d1,d2));
            }
            prev=cur;
        }
        int mini = 1e9;
        for(int j=0; j<n;j++){
            mini = min(mini,prev[j]);
        }
        return mini;
    }
};