class Solution {
public:
    int getFirst(vector<int>& arr, int target){
        int l=0,h=arr.size()-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==target){
                ans=mid;
                h=mid-1;
            }
            else if(arr[mid]>target)   h=mid-1;
            else    l=mid+1;
        }
        return ans;
    }
    int getLast(vector<int>& arr, int target){
        int l=0,h=arr.size()-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==target){
                ans=mid;
                l=mid+1;
            }
            else if(arr[mid]>target)    h=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(getFirst(nums,target)==-1)   return {-1,-1};
        return {getFirst(nums,target),getLast(nums,target)};
    }
};