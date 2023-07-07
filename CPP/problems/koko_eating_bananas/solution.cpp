class Solution {
public:
    long long countHours(int num,vector<int>& arr){
        long long hours=0;
        for(int i=0;i<arr.size();i++){
            hours+=ceil((double)arr[i]/num);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& arr, int k) {
        int l=1,h=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            long long totalH=countHours(mid,arr);
            if(totalH<=k){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
};