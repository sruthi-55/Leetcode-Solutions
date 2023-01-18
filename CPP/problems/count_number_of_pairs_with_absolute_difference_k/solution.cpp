class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[i]==k)
                    count++;
            }
        }
        return count;
    }
};