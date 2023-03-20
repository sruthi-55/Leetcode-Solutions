class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        //{stops,{node,dist}}
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int neiNode=it.first;
                int cost=it.second;
                if(dis+cost<dist[neiNode] && stops<=k) {
                    dist[neiNode]=dis+cost;
                    q.push({stops+1,{neiNode,dis+cost}});
                }
            }
        }
        if(dist[dst]==1e9)   return -1;
        else return dist[dst];
    }
};