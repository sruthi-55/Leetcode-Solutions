class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for(auto e:richer){
            inDegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)  q.push(i);
        }
        
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        while(!q.empty()){
            int u=q.front(); q.pop();

            for(auto v:adj[u]){
                if(quiet[ans[v]]>quiet[ans[u]])     //why can't it be quiet[v]>quiet[u]
                    ans[v]=ans[u];
                if(--inDegree[v]==0)  q.push(v);
            }
        }
        return ans;
    }
};