class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int xorr=0;
        for(int i=0;i<arr.size();i++){
            xorr^=(arr[i]^i);
        }
        return xorr^arr.size();
    }
};