class Solution {
public:
    int maxDepth(string s) {
        int res,cur=0;
        for(char c:s){
            if(c=='('){
                res = max(res,++cur);
            }
            else if(c==')'){
                cur--;
            }
        }
        return res;
    }
};