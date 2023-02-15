class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s1[i1-1]==s2[i2-1])  dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        int l=dp[n1][n2];
        string s="";
        int ind=l-1;
        int i=n1,j=n2;
        while(i>0&&j>0){
            if(s1[i-1]==s2[j-1]){
                s+=s1[i-1];ind--;
                i--;j--;
            }
            //up>left
            else if(dp[i-1][j]>dp[i][j-1]){
                s+=s1[i-1];i--;
            }
            else{
                s+=s2[j-1];j--;
            }
        }
        while(i>0){
            s+=s1[i-1];
            i--;
        }	
        while(j>0){
            s+=s2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }

};