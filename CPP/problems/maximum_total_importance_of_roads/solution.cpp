class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res=0;
        vector<long long> degree(n);
        for(auto e:roads){
            degree[e[0]]++;
            degree[e[1]]++;
        }
        sort(degree.begin(),degree.end());
        for(int i=0;i<n;i++){
            res+=degree[i]*(i+1);
        }
        return res;
    }
};