class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int xorr=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        long long int lastSet= xorr & ~(xorr-1);
        int first=0,second=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&lastSet)
                first^=nums[i];
            else    second^=nums[i];
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};