class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> stack;
        for(char i: s){
            if(i=='('){
                if(!stack.empty())  res+='(';
                stack.push('(');
            }
            else{
                char c=stack.top();
                stack.pop();
                if(!stack.empty())  res+=')';
            }
        }
        return res;
    }
};