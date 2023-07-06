class Solution {
public:
    vector<string> res;
    unordered_map<string,int> m;
    vector<string> removeInvalidParentheses(string s) {
        solve(s,getMinInvalid(s));
        return res;
    }
    int getMinInvalid(string s){
        stack<char> stack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')   stack.push('(');
            else if(s[i]==')'){
                if(stack.size()!=0 && stack.top()=='(')
                    stack.pop();
                else    stack.push(')');
            }
        }
        return stack.size();
    }
    void solve(string s,int minInv){
        if(m[s])    return;
        else    m[s]++;
        if(minInv<0)    return;
        if(minInv==0){
            if(!getMinInvalid(s))
                res.push_back(s);
            return;
        }
        for(int i=0;i<s.length();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,minInv-1);
        }
    }
};