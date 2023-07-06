class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')   stack.push(i);
            else if(s[i]==')'){
                if(stack.size()!=0 && s[stack.top()]=='(') 
                    stack.pop();
                else    stack.push(i);
            }
        }
        while(!stack.empty()){
            s.erase(stack.top(),1);
            stack.pop();
        }
        return s;
    }
    
};