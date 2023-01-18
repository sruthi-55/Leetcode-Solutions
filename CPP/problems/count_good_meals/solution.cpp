class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=pow(2,21);j*=2){
                if(m.find(j-nums[i])!=m.end()){
                    res+=m[j-nums[i]];
                }
            }
            m[nums[i]]++;
        }
        return res % (int)(1e9 + 7);
    }
};