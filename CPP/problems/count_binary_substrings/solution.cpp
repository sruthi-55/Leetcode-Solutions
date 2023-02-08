class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int ans=0;
        int prev=0,cur=1;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans+=min(cur,prev);
                prev=cur;
                cur=1;
            }
            else{
                cur++;
            }
        }
        return ans+min(prev,cur);
    }
};