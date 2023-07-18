class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n<=1)    return "";
        //if char is not 'a' make it a
        //check only till half of substring 
        //if all are a's make last char as 'b'
        for(int i=0;i<n/2;i++){
            //abccba --> aaccba
            //aabcbaa --> aaacbaa
            //aaaa --> aaab
            if(s[i]!='a'){
                s[i]='a';
                return s;
            }
        }
        s[n-1]='b';
        return s;
    }
};