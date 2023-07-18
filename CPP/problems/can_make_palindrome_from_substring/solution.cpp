class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        //s-->  abcda 
        //s[0] --> {0,0,0,0,0,...0}
        //s[1] --> {1,0,0,0,0,...0} --first char updated here
        //  ....
        //s[n-1] --> {,,,,,,,}
        //s[n] --> {,,,,,,,,}

        vector<vector<int>> v(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++){
            v[i+1][s[i]-'a']++;
            for(int j=0;j<26;j++){
                v[i+1][j]+=v[i][j];
            }
        }
        vector<bool> res;
        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right=queries[i][1];
            int k=queries[i][2];
            if(right-left+1<=k) res.push_back(true);
            else{
                int odd=0;
                for(int j=0;j<26;j++){
                    //bw left to right how many odd char frequencies
                    int c=v[right+1][j]-v[left][j];
                    if(c%2) odd++;
                }
                //replace one odd with another odd
                //so 2 odd gets reduced with one replacement
                odd-=2*k;
                if(odd>1)   res.push_back(false);
                else    res.push_back(true);
            }
        }
        return res;
    }
};