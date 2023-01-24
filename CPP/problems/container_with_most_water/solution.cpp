class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int l=0,h=n-1;
        while(l<=h){
            int width = h-l;
            ans = max(ans,min(height[l],height[h])*width);
            if(height[l]<=height[h]) l++;
            else h--;
        }
        return ans;
    }
};