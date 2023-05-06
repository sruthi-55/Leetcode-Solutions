class Solution {
public:
    class tuple{
    public:
        int node; 
        int mask;
        int cost;
        tuple(int node, int mask, int cost){
            this -> node = node;
            this -> mask = mask;
            this -> cost = cost;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple> q;
        set<pair<int, int>> s;
        int all = (1 << n) - 1; //2^n-1
        for(int i = 0; i < n; i++){
            int maskValue = (1 << i); //2^i
            tuple thisNode(i, maskValue, 1);
            q.push(thisNode);
            s.insert({i, maskValue}); 
        }
        
        while(q.empty() == false){
            tuple curr = q.front(); q.pop();
            if(curr.mask == all)    return curr.cost - 1;
            for(auto &adj: graph[curr.node]){
                int newMask = curr.mask | (1 << adj); 
                tuple ThisNode(adj, newMask, curr.cost + 1);
                if(s.find({adj, newMask}) == s.end()){
                    s.insert({adj, newMask}); 
                    q.push(ThisNode); 
                }
            }
        }
        return -1;
    }
};