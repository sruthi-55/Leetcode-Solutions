class Solution {
public:
    int scoreOfParentheses(string s) {
        //str --> ( () (()) )
        //"(" --> -1
        stack<int> stk;
        for(auto ch:s){
            if(ch=='(') stk.push(-1);
            else{
                char lastCh = stk.top();
                if(lastCh == -1){
                    stk.pop(),stk.push(1);
                }   
                else{
                    int val=0;
                    while(!stk.empty() && stk.top()!=-1){
                        val+=stk.top();
                        stk.pop();
                    }   
                    stk.pop();
                    stk.push(2*val);
                }
            }
        }
        int val=0;
        while(!stk.empty())
            val+=stk.top(),stk.pop();
        return val;
    }
};