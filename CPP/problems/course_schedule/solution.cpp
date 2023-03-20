class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
			vector<int> res;
			vector<int> adj[V];
			for(auto it:prerequisites){
				adj[it[1]].push_back(it[0]);
			}
			
			vector<int> inDegree(V,0);
	    queue<int> q;
	    for(int i=0;i<V;i++){
				for(auto it:adj[i]){
					inDegree[it]++;
				}
	    }
	    
	    for(int i=0;i<V;i++){
				if(inDegree[i]==0)  q.push(i);
	    }
	    
	    while(!q.empty()){
				int node=q.front();
				q.pop();
				res.push_back(node);
				for(auto nei:adj[node]){
					inDegree[nei]--;
					if(inDegree[nei]==0)    q.push(nei);
				}
	        
	    }
	    
	    if(res.size()==V)   return true;
	    else return false;
    }
};