class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        int mask=0;
        unordered_map<int,int> count;
        count[0]=1;
        for(char c: word){
            int ind=c-'a';
            mask^= (1<<ind);
            ans+= count[mask];
            for(int i=0;i<10;i++){
                int lookFor = mask^(1<<i);
                ans+= count[lookFor];
            }
            count[mask]++;
        }
        return ans;
    }
};