class Solution {
public:
    void dfs(int i,vector<vector<int>> &res,vector<vector<int>> &graph,vector<int> &path){
        path.push_back(i);
        if(i==graph.size()-1)   res.push_back(path);
        for(auto it:graph[i]){
            dfs(it,res,graph,path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0,res,graph,path);
        return res;
    }
};