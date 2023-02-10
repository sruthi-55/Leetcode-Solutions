class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        vector<int>ans;
        for(int i = 0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        for(int i = 0;i<nums2.size();i++){
            if (m[nums2[i]] > 0){
                m[nums2[i]]--; 
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};