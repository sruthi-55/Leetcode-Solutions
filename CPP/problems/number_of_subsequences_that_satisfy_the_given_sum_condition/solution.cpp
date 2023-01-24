class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod = 1e9+7;
        int count=0;
        int l=0,h=nums.size()-1;

        //vector power stores the count of number of 
        //subsequences possible with i characters
        vector<int> power(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            power[i]=power[i-1]*2%mod;
        }
        
        while(l<=h){
            if(nums[l]+nums[h]>target){
                h--;
            }
            else{
                count = (count+ power[h-l])%mod;
                l++;
            }
        }
        return count;
    }
};