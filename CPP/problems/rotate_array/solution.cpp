class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> first;
        //storing last k elements
        for(int i=n-k;i<n;i++){
            first.push_back(nums[i]);
        }
        //shifting elements right by k places
        for(int i=n-k-1; i>=0; i--){
            nums[i+k]=nums[i];
        }

        for(int i=0;i<k;i++){
            nums[i]=first[i];
        }
    }
};