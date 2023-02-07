class Solution {
public:
    string reverseStr(string s, int k) {
        for(int start=0;start<s.size();start+=2*k){
            int i=start,j=min((int)s.size()-1,start+k-1);
            while(i<j){
                char temp=s[i];
                s[i++]=s[j];
                s[j--]=temp;
            }
        }
        return s;
    }
};