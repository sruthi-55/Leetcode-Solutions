class Solution {
public:
    int find(int i,int k,bool buy,vector<int> &arr,vector<vector<int>> &dp){
        if(i>=arr.size()||k<=0)   return 0;
        if(dp[i][buy]!=-1)    return dp[i][buy];
        if(buy) return dp[i][buy]=max(-arr[i]+find(i+1,k,!buy,arr,dp), find(i+1,k,buy,arr,dp));
        else    return dp[i][buy]=max(arr[i]+find(i+1,k-1,!buy,arr,dp), find(i+1,k,buy,arr,dp));
    }
    int maxProfit(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(0,1,1,arr,dp);
    }
};