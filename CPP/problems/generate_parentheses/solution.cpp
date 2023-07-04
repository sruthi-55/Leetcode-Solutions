class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingPar(res,"",0,0,n);
        return res;

    }
    void addingPar( vector<string> &res,string str,int open,int close,int n){
        if(open==n && close==n){
            res.push_back(str);
            return;
        }
        if(open<n) addingPar(res,str+"(",open+1,close,n);
        if(close<open) addingPar(res,str+")",open,close+1,n);

    }
};