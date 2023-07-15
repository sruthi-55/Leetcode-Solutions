class Solution {
public:
    //2 pointer and recursion --Accepted
    //TC: O(n^2)
    //SC: O(n)
    string shortestPalindrome(string s) {
        int n=s.size();
        int i=0;
        //aaabcbde
        //i=0,j=2
        //i=3,j=-1
        for(int j=n-1;j>=0;j--){
            if(s[i]==s[j])  i++;
        }
        if(i==n)    return s;
        string remainS=s.substr(i);
        reverse(remainS.begin(),remainS.end());
        return remainS+shortestPalindrome(s.substr(0, i))+s.substr(i);
    }
    //s== a d c b a
    // rev(i)+s XXX
    // rev(i)+f(0,i)+s(i)
};