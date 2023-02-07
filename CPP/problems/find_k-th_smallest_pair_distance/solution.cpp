class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,h=nums[n-1]-nums[0];
        
        while(l<h){
            int mid=(h+l)/2,cnt=0;
            for(int i=0,j=0;i<n;i++){
                while(j<n && nums[j]-nums[i]<=mid) j++;
                cnt+=j-i-1;
            }
            if(cnt<k)   l=mid+1;
            else h=mid;
        }
        return l;
    }
};

