class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int opened=0;
        for(char i: s){
            //opened is not >0 but we need to increment opened
            if(i=='(' && opened++>0){
                res+=i;
            }
            else if(i==')' && opened-->1){
                res+=i;
            }
        }
        return res;
        
    }
};