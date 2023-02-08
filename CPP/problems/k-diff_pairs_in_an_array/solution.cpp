class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for (int i = 0, j = 1; j < nums.size();) {
            if (j <= i || nums[i] + k > nums[j]) {
                j++;
            } 
            else if (i > 0 && nums[i] == nums[i - 1] || nums[i] + k < nums[j]) {
                i++;
            } 
            else {
                ans++;
                i++;
            }
        }
        return ans;
    }
};