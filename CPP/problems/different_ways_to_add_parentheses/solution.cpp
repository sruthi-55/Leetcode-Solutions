class Solution {
public:
    int perform(int a,int b,char op){
        if(op=='+') return a+b;
        if(op=='-') return a-b;
        if(op=='*') return a*b;
        return 0;
    }


    vector<int> diffWaysToCompute(string exp) {
        vector<int> results;
        bool isNumber=1;

        
        for(int i=0;i<exp.length();i++){
            if(!isdigit(exp[i])){
                isNumber=0;
                vector<int> left= diffWaysToCompute(exp.substr(0,i));
                vector<int> right= diffWaysToCompute(exp.substr(i+1));
                for(int a:left){
                     for(int b:right){
                        int val = perform(a,b,exp[i]);
                        results.push_back(val);
                    }
                }
                   
            }
        }
        if(isNumber==1) results.push_back(stoi(exp));
        return results;
        
    }
};