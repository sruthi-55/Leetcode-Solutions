class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n=arr.size();
        int c=0,maxi=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                c++;
                maxi=max(maxi,c);
            }
            else    c=0;
        }
        return maxi;
    }
};