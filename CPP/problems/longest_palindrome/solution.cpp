class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int> m;
        for(char c:s)
            m[c]++;
        bool oddFound=false;
        for(auto it:m){
            if(it.second%2==0)  ans+=it.second;
            else if(it.second%2==1){
                oddFound=true;
                ans+=it.second-1;
            }
        }
        if(oddFound)    ans+=1;
        return ans;
    }
};