class Solution {
public:
    int lcs(string s1, string s2){
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s1[i1-1]==s2[i2-1])  dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        return dp[n1][n2];
    }

    int minInsertions(string &s1){
        string s2=s1;
        reverse(s1.begin(),s1.end());
        return s1.size()-lcs(s1,s2);

    }
};