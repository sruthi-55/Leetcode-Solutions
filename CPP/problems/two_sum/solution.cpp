class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (target!=nums[i]*2 && m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], i};
            }
            else if(target==nums[i]*2 && m[nums[i]]!=i){
                return {m[target - nums[i]], i};
            }
        }
        return {};
    }
};