class Solution {
public:
    string interpret(string cmd) {
    unordered_map<string,string> rep = {{"G", "G"}, {"()", "o"}, {"(al)", "al"}};
        string t, res;
        for(auto c: cmd){
            t += c;
            if(rep.find(t) != rep.end()){
                res += rep[t];
                t = "";
            }
        }
        return res;
    }
};