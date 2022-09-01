class Solution {
public:
    int countMatches(vector<vector<string>>& items, string key, string ruleValue) {
        int idx = key == "type" ? 0 : key == "color" ? 1 : 2;
        int c=0;
        for(int i=0;i<items.size();i++){
                if(items[i][idx]==ruleValue)
                    c++;
            
        }
        return c;
    }
};