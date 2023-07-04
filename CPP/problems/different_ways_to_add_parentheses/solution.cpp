class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='*' || exp[i]=='-' || exp[i]=='+'){
                vector<int> left= diffWaysToCompute(exp.substr(0,i));
                vector<int> right= diffWaysToCompute(exp.substr(i+1));
                for(int a:left){
                     for(int b:right){
                        if(exp[i]=='+') res.push_back(a+b);
                        else if(exp[i]=='-') res.push_back(a-b);
                        else res.push_back(a*b);
                    }
                }
            }
        }
        //if we find no operator
        //ca't divide further
        if(res.size()==0) res.push_back(stoi(exp));
        return res;
        
    }
};