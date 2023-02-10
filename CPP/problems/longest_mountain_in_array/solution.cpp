class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int base=0,end=0;
        int ans=0;
        while(base<n){
            end=base;
            if(end+1<n && arr[end]<arr[end+1]){
                while(end+1<n && arr[end]<arr[end+1])   end++;
                //check for decreasing slope only after finding increasing slope
                if(end+1<n && arr[end]>arr[end+1]){
                    while(end+1<n && arr[end]>arr[end+1])   end++;
                    ans = max(ans,end-base+1);
                }
            }
            base=base+1;
        }
        return ans;
    }
};