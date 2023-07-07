class Solution {
public:
    bool possible(int d,vector<int>& arr,int threshold){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/d);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int l=1,h=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(mid,arr,threshold)){
                ans=mid;
                h=mid-1;
            }     
            else    l=mid+1;
        }
        return ans;
    }
};