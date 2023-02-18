class Solution {
public:
    int maxProfit(int k,vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> ahead(2,vector<int> (k+1,0));
        vector<vector<int>> cur(2,vector<int> (k+1,0));
        for(int i = n-1; i>=0; i--){
            for(int b = 0; b<=1; b++){
                for(int t=1; t<=k; t++){
                    if(b==0){// We can b the stock
                        cur[b][t] = max(0+ahead[0][t], 
                                    -arr[i] + ahead[1][t]);
                    }
                    if(b==1){// We can sell the stock
                        cur[b][t] = max(0+ahead[1][t],
                                    arr[i] + ahead[0][t-1]);
                    }
                }
            }
            ahead=cur;
        }
        return ahead[0][k];
    }
};