class Solution {
public:
    int longestValidParentheses(string s) {
        int maxL=0;
        int open=0,close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')   open++;
            else    close++;
            if(open==close)     maxL=max(maxL,2*open);
            else if(close>open){
                open=0;close=0;
            }
        }
        open=0;close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(')   open++;
            else    close++;
            if(open==close)     maxL=max(maxL,2*open);
            else if(open>close){
                open=0;close=0;
            }
        }
        return maxL;
    }
};