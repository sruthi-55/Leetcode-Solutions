class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        stack.push(0);
        for(auto i:s){
            if(i=='('){
                stack.push(0);
            }
            else{
                int v= stack.top();
                stack.pop();
                int w= stack.top();
                stack.pop();
                stack.push(w+ max(2*v,1));
            }
        }
        return stack.top();
    }
};