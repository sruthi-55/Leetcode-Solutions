class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        for(auto i:str){
            if(i=='('){
                s.push(-1);
            }
            else{
                if(s.top()==-1){
                    s.pop();
                    s.push(1);
                }
                else{
                    int val=0;
                    while(s.top()!=-1){
                        val+=s.top();s.pop();
                    }
                    s.pop();
                    s.push(2*val);
                }
            }
        }
        int val=0;
        while(s.size()!=0)  val+=s.top(),s.pop();
        return val;
    }
};