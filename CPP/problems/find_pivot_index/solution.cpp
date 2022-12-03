class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s=0;
        int leftS=0;
        for(int i=0;i<nums.size();i++) s+=nums[i];
        for(int i=0;i<nums.size();i++){
            if(leftS== s-leftS-nums[i])
                return i;
            leftS+=nums[i];
        }
        return -1;
    }
};