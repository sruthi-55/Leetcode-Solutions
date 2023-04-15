class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        for(char s:S){
            for(char j:J){
                if(s==j)    ans++;
            }
        }
        return ans;
    }
};