class Solution {
public:
    int titleToNumber(string str) {
        int ans=0;
        for(char c:str){
            int d=c-'A'+1;
            ans=ans*26+d;
        }
        return ans;
    }
};