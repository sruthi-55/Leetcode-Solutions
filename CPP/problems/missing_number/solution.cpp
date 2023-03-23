class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int N=arr.size();
        int sum=(N*(N+1))/2,s=0;
        for(int i=0;i<N;i++){
            s+=arr[i];
        }
        return sum-s;
        }
};