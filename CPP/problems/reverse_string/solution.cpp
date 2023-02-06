class Solution {
public:
    void reverseString(vector<char>& s) {
        int h=0,t=s.size()-1;
        while(h<t){
            swap(s[h++],s[t--]);
        }
    }
};