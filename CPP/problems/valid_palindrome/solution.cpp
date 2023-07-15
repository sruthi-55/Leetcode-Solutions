class Solution {
public:
    bool isPalindrome(string s) {
        int h=0,t=s.size()-1;
        for(;h<t;h++,t--){
            while(!isalnum(s[h]) && h<t)   h++;
            while(!isalnum(s[t]) && h<t) t--;
            if(tolower(s[h])!=tolower(s[t]))    return false;
        }
        return true;
    }
};