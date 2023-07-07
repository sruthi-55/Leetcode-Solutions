class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res=0;
        vector<int> state(words.size());
        for(int i=0;i<words.size();i++){
            for(char c:words[i])
                state[i] |= 1<<(c-'a');
            for(int j=0;j<i;j++)
                if(!(state[i]&state[j]))
                    res=max(res,(int)(words[i].size()*words[j].size()));
        }
        return res;
    }
};