class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int left=-1,right=-1;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=L){
                right=i;
            }
            if(nums[i]>R){
                left=i;
            }
            res+=right-left;
        }
        return res;
    }
};