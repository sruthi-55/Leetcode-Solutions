class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int mini=arr[0];
        int res=0;
        for(int i=1;i<n;i++){
            res=max(res,arr[i]-mini);
            mini=min(mini,arr[i]);
        }
        return res;
    }
};