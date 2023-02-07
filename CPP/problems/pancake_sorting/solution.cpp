class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for(int h=arr.size();h>0;h--){
            int i;
            for(i=0;arr[i]!=h;i++);
            reverse(arr.begin(),arr.begin()+i+1);
            res.push_back(i+1);
            reverse(arr.begin(),arr.begin()+h);
            res.push_back(h);
        }
        return res;
    }
};