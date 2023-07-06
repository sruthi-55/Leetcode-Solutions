class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cSet=0,cUnset=0;
            for(int j=0;j<nums.size();j++){
                if((1<<i)&nums[j])  cSet++;
                else    cUnset++;
            }
            ans+=cSet*cUnset;
        }
        return ans;
    }
};