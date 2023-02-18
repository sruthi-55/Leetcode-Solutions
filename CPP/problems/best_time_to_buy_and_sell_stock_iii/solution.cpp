class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i = n-1; i>=0; i--){
            for(int b = 0; b<=1; b++){
                for(int t=1; t<=2; t++){
                    if(b==0){// We can b the stock
                        dp[i][b][t] = max(0+dp[i+1][0][t], 
                                    -arr[i] + dp[i+1][1][t]);
                    }
                    if(b==1){// We can sell the stock
                        dp[i][b][t] = max(0+dp[i+1][1][t],
                                    arr[i] + dp[i+1][0][t-1]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};