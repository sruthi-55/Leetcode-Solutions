class Solution {
public:
    bool possible(int day,vector<int> &arr,int m,int k){
        int c=0;
        int boquets=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                c++;
            }
            else{
                boquets+=c/k;
                c=0;
            }
        }
        boquets+=c/k;
        if(boquets>=m)   return true;
        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int l=*min_element(arr.begin(),arr.end());
        int h=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(mid,arr,m,k)){
                ans=mid;
                h=mid-1;
            }   
            else{
                l=mid+1; 
            }        
        }
        return ans;
    }
};