class Solution {
public:
    int longestDecomposition(string s) {
        int n=s.size();
        int count=0;
        //ghi abcdef hello adam hello abcdef ghi
        string l="",r="";
        for(int i=0;i<n;i++){
            l=l+s[i];    r=s[n-i-1]+r;
            if(l==r){
                count++;
                l="",r="";
            }
        }
        return count;
    }
};