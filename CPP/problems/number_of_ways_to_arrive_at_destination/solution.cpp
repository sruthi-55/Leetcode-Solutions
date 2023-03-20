class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(int)(1e9+7);
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LLONG_MAX),ways(n,0);
        //{dis,node}
        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>, greater<>> pq;
        dist[0]=0;ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long dis=pq.top().first;
            int node=pq.top().second;
            // if(dist[node] < dis) continue;
            pq.pop();
            for(auto it:adj[node]){
                long cost=it.second;
                int neiNode=it.first;
                if(cost+dis<dist[neiNode]){
                    dist[neiNode]=dis+cost;
                    pq.push({dis+cost,neiNode});
                    ways[neiNode]=ways[node];
                }
                else if(cost+dis==dist[neiNode]){
                    ways[neiNode]=(ways[neiNode]+ways[node])%mod;
                }
            }
        }
        return int(ways[n-1])%mod;
    }
};