class Solution {
public:
    int lcs(string s1, string s2){
    int n1=s1.size(),n2=s2.size();
    vector<int> prev(n2+1,0),cur(n2+1,0);
    
    for(int i1=1;i1<=n1;i1++){
        for(int i2=1;i2<=n2;i2++){
            if(s1[i1-1]==s2[i2-1])  cur[i2]=1+prev[i2-1];
            else cur[i2]=max(prev[i2],cur[i2-1]);
        }
        prev=cur;
    }
    return prev[n2];
}
    int longestPalindromeSubseq(string s1){
        string s2=s1;
        reverse(s1.begin(),s1.end());
        return lcs(s1,s2);
    }
};

