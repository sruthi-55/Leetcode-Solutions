class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n);
        vector<vector<int>> graph(n, vector<int>());
        for (auto e : relations) {
            int a = e[0] - 1, b = e[1] - 1;
            graph[a].push_back(b);
            inDegree[b]++;
        }
        //dist[u] is the number of months required to finish u course
        vector<int> dist(n);
        queue<int> q;
        for (int i=0;i<n;i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                dist[i] = time[i];
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]);
                if (--inDegree[v] == 0) 
                    q.push(v);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};