class Solution {
public:
    int findRadius(vector<int>& A, vector<int>& H) {
        sort(A.begin(),A.end());
        sort(H.begin(),H.end());
        vector<int> res(A.size(),INT_MAX);
        for(int i=0,j=0;i<A.size()&&j<H.size();){
            if(A[i]<=H[j]){
                res[i]=H[j]-A[i];
                i++;
            }  
            else    j++;
        }
        for(int i=A.size()-1,j=H.size()-1;i>=0&&j>=0;){
            if(A[i]>=H[j]){
                res[i]=min(res[i],A[i]-H[j]);
                i--;
            }  
            else    j--;
        }
        return *max_element(res.begin(),res.end());
    }
};