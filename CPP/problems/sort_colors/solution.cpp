class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int i=0;
        while(i<=h){
            if(nums[i]==0){
                swap(nums[i],nums[l++]);i++;
            }
            else if(nums[i]==1){
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[h--]);;
            }
        }
    }
};