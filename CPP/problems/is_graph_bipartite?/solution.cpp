class Solution {
public:
    bool dfs(int i,int col,vector<vector<int>> &graph,int color[]) {
        color[i]=col;
        for(auto it:graph[i]){
            if(color[it]==-1 ){
                if(dfs(it,!col,graph,color)==false){
                    return false;
                }  
            } 
            else if(color[it]==col){
               return false; 
            } 
        }
        return true;
    }
    bool bfs1(int i,int col,vector<vector<int>> &graph,int color[]){
        queue<int> q;
        q.push(i);
        color[i]=col;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }
                else if(color[it]==color[node])   return false;
            }
        }
        return true;
    }

    bool bfs(int i,int col,vector<vector<int>> &graph,int color[]){
        queue<pair<int,int>> q;
        q.push({i,col});
        color[i]=col;
        while(!q.empty()){
            int node=q.front().first;
            int nCol=q.front().second;
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    q.push({it,!nCol});
                    color[it]=!nCol;
                }
                else if(color[it]==nCol)   return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        int m=graph.size();
        int color[m];
        for(int i=0;i<m;i++)    color[i]=-1;
        for(int i=0;i<m;i++){
            if(color[i]==-1){
                if(bfs(i,0,graph,color)==false){
                    return false;
                }    
            }
        }
        return true;
    }
};