class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingPar(res,"",n,0);
        return res;

    }
    void addingPar( vector<string> &res,string str,int n,int m){
        //if there is no left parenthesis or right parenthesis to add
        if(n==0 && m==0){
            res.push_back(str);
            return;
        }
        if(n>0) addingPar(res,str+"(",n-1,m+1);
        if(m>0) addingPar(res,str+")",n,m-1);

    }
};