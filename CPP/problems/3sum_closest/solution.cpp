class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)   return 0;
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int first=0;first<nums.size();first++){
            if(first>0 && nums[first]==nums[first-1])   continue;
            int second = first+1;
            int third = nums.size()-1;
            while(second<third){
                int curSum = nums[first]+nums[second]+nums[third];
                if(curSum==target)  return curSum;
                if(abs(curSum-target)<abs(closest-target))  
                    closest=curSum;     
                if(curSum>target)
                    third--;
                else
                    second++;          
            }
        }
        return closest;
    }
};