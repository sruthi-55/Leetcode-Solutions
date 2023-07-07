class Solution {
public:
    bool possible(int w,vector<int> &arr,int days){
        int totalDays=1;
        int load=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+load>w){
                load=arr[i];
                totalDays++;
            }
            else    load+=arr[i];
        }
        return totalDays<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(),arr.end(),0);
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(mid,arr,days)){
                ans=mid;
                h=mid-1;
            } 
            else    l=mid+1;
        }
        return ans;
    }
};