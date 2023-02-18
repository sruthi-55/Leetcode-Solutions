class Solution {
public:
    bool isAllStars(string & s1, int i) {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++) {
            if (s1[j - 1] != '*')
            return false;
        }
        return true;
    }
    bool isMatch(string s2, string s1) {
        int n1=s1.size();
        int n2=s2.size();
        vector<bool> prev(n2+1, false),cur(n2+1, false);
        
        prev[0]=true;
        for (int i=1; i<=n1; i++) {
            cur[0] = isAllStars(s1, i);
            for (int j=1; j<=n2; j++) {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                cur[j] = prev[j - 1];
                else {
                    if (s1[i - 1] == '*')
                    cur[j] = prev[j] || cur[j - 1];
                    else cur[j] = false;
                }
            }
            prev=cur;
        }
    return prev[n2];
    }
};