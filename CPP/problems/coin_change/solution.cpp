class Solution {
public:
    int coinChange(vector<int>& arr, int T) {
        int n=arr.size();
        vector<int> prev(T+1,0),cur(T+1,0);
        
        for(int i=0;i<=T;i++){
            if(i%arr[0]==0) prev[i]=i/arr[0];
            else prev[i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=T;t++){
                int nTake=prev[t];
                int take=1e9;
                if(arr[i]<=t){
                    take=1+cur[t-arr[i]];
                }
                cur[t]=min(take,nTake);
            }
            prev=cur;
        }
        int ans=prev[T];
        if(ans>=1e9)    return -1;
        else return ans; 
    }
};