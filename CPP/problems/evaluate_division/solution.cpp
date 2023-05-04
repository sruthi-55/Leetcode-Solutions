class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> adj;
    unordered_map<string,bool> vis;
    double queryAns;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size(), m=queries.size();
        vector<double> ans(m);
        
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            vis[equations[i][0]]=false;
            vis[equations[i][1]]=false;
        }
        for(int i=0;i<queries.size();i++){
            queryAns=1;
            bool pathFound=dfs(queries[i][0],queries[i][1],1);
            if(pathFound)   ans[i]=queryAns;
            else    ans[i]=-1;
        }
        return ans;
    }
    bool dfs(string s,string e,double runningProduct){
        if(s==e && adj.find(s)!=adj.end()){
            queryAns=runningProduct;
            return true;
        }
        vis[s]=true;
        bool tempAns=false;
        for(int i=0;i<adj[s].size();i++){
            if(!vis[adj[s][i].first]){
                tempAns = dfs(adj[s][i].first,e,runningProduct*adj[s][i].second);
                if(tempAns)    break;
            }
        }
        vis[s]=false;
        return tempAns;
    }
};