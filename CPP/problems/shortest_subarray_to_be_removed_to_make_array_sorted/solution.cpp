class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int res=0,n=arr.size();
        int r=n-1;
        while(r>0 && arr[r-1]<=arr[r])  r--;
        res=r;
        for(int l=0;l < r && (l==0 || arr[l-1]<=arr[l]);l++){
            while(r<n && arr[r]<arr[l]) r++;
            res = min(res,r-l-1);
        }
        return res;
    }
};