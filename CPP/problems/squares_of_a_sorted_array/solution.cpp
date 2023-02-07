class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int l=0,h=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[l])>abs(nums[h])){
                res[i]=nums[l]*nums[l++];
            }   
            else{
                res[i]=nums[h]*nums[h--];
            }  
        }
        return res;

    }
};