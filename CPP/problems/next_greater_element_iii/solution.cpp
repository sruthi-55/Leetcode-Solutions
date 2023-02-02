class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i= s.length()-2;
        while(i>=0 && s[i+1]<=s[i]) i--;
        if(i<0) return -1;
        else if(i>=0){
            int j=s.length()-1;
            while(s[j]<=s[i] && i<j) j--;
            swap(s[i],s[j]);
            reverse(s.begin()+i+1,s.end());
        }
        long next= stol(s);
        return next>INT_MAX? -1:next;
    }
};