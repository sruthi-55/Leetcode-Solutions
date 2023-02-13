class Solution {
public:
    int f(vector<int> &nums){
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int notTake=0+prev;
            int cur=max(take,notTake);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==0)    return 0;
        if(n==1)    return arr[0];
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<n;i++){
            if(i!=n-1)
                arr1.push_back(arr[i]);
            if(i!=0)
            arr2.push_back(arr[i]);
        }
        int ans1 = f(arr1);
        int ans2 = f(arr2);
        return max(ans1,ans2);
    }
};


