class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<int> prev(k+1,0);
        
        for(int i=0;i<n;i++)    prev[0]=1;
        if(arr[0]<=k)   prev[arr[0]]=1;
        for(int i=1;i<n;i++){
            vector<int> cur(k+1,0);
            cur[0]=1;
            for(int t=1;t<=k;t++){
                int notTake=prev[t];
                int take=0;
                if(arr[i]<=t)   take=prev[t-arr[i]];
                cur[t]=notTake||take;
            }
            prev=cur;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2==1)	return 0;
        else	return subsetSumToK(n,sum/2,arr);
    }
};