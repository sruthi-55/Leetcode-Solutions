class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return recursive(nums, low, high, target);
    }
    int recursive(vector<int>& nums, int low, int high, int target) {
        if(low > high) return -1;
        int mid = (low + high) / 2;
        
        if(nums[mid] == target) return mid;
        
        else if(target > nums[mid]) 
            return recursive(nums, mid + 1, high, target);
        else return recursive(nums, low, mid - 1, target);
    }
};