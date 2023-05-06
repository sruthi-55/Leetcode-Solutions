class Solution {
public:
    vector<int> validOrder(vector<vector<int>> &conds, int k){
        vector<int> inDegree(k+1, 0);
        vector<vector<int>> adj(k+1);
        for(auto c:conds){
            inDegree[c[1]]++;
            adj[c[0]].push_back(c[1]);
        }
        //Kahn's algo
        vector<int> order;
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(inDegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int x:adj[node]){
                inDegree[x]--;
                if(inDegree[x]==0)  q.push(x);
            }
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        vector<int> validR = validOrder(rowC, k);
        vector<int> validC = validOrder(colC, k);
        if(validC.size()!=k||validR.size()!=k) return {};

        vector<vector<int>> validMatrix(k, vector<int>(k, 0));
        for(int i = 0;i<k;i++){
            for(int j = 0 ; j<k ; j++){
                if(validR[i]==validC[j]){
                    validMatrix[i][j]=validR[i];
                }
            }
        }
        return validMatrix;
    }
};