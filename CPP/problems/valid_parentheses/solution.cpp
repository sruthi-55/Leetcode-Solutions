class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto i:s){
            if(i=='(' || i=='[' || i=='{'){
                stack.push(i);
            }
            else if(stack.empty() || (stack.top()=='(' && i!=')') || (stack.top()=='[' && i!=']') || (stack.top()=='{' && i!='}')){
                return false;
            }
            else    stack.pop();
        }
        return stack.empty();
    }
};