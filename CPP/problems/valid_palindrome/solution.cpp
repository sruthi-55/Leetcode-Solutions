class Solution {
public:
    bool isPalindrome(string s) {
        int h=0,t=s.size()-1;
        for(int h=0,t=s.size()-1;h<t;h++,t--){
            while(!isalnum(s[h]) && h<t)   h++;
            while(!isalnum(s[t]) && h<t) t--;
            if(toupper(s[h])!=toupper(s[t]))    return false;
        }
        return true;
    }
};