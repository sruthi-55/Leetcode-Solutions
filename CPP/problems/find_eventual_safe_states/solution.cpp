class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis,int check[]){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,check)) return true;
            }
            else if(pathVis[it]==1) return true;
        }
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> res;
        vector<int> adjRev[V];
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto nei:adj[i]){
                adjRev[nei].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
	        if(inDegree[i]==0)  q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        res.push_back(node);
	        for(auto nei:adjRev[node]){
	            inDegree[nei]--;
	            if(inDegree[nei]==0)    q.push(nei);
	        }
	        
	    }
        sort(res.begin(),res.end());
        return res;
    }
};