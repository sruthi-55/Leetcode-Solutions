class Solution {
public:
    //to avoid getting memory limit exceeded pass string by reference
    bool isPalindrome(int s,int e,string &str){
        while (s<e) {
            if (str[s] != str[e])   return false;
            s++;    e--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        if(n<=1)    return 0;
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
            dp[i]= mini;
        }
        return dp[0]-1;
    }
};