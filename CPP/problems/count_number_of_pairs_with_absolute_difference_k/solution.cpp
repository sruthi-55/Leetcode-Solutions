
class Solution{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            int val1 = m[nums[i] + k];
            int val2 = m[nums[i] - k];
            ans += val1 + val2;
            // adding nums[i] into map
            m[nums[i]]++;
        }
        return ans;
    }
};
