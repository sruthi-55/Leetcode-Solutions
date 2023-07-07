class Solution {
public:
    int mySqrt(int n) {
        int l=1,h=n;
        int ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(mid*mid==n)  return mid;
            else if(mid*mid<n){
                ans=mid;
                l=mid+1;
            }  
            else    h=mid-1;
        }
        return ans;
    }
};