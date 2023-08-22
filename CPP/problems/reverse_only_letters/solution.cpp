class Solution {
public:
    bool isLetter(char c){
        c=tolower(c);
        if(c>=97 && c<=122) return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            while(l<h && !isLetter(s[l]))  l++;
            while(l<h && !isLetter(s[h]))  h--;
            swap(s[l],s[h]);
            l++;h--;
        }
        return s;
    }
};