class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<(1<<n);i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                if((1<<j)&i)    v.push_back(nums[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};