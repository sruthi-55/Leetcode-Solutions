class UnionFind{
    vector<int> par;
    vector<int> rank;
    int components;
public:
    UnionFind(int n){
        components=n;
        for(int i=0;i<=n;i++){
            par.push_back(i);
            rank.push_back(1);
        }
    }
    int findPar(int x){
        if(x==par[x])   return x;
        return par[x]=findPar(par[x]);
    }
    int uni(int x,int y){
        x=findPar(x); y=findPar(y);
        if(x==y)    return 0;
        if(rank[x]>rank[y]){
            par[y]=x;
            rank[x]+=rank[y];
        }
        else{
            par[x]=y;
            rank[y]+=rank[x];
        }
        components--;
        return 1;
    }
    bool isConnected(){
        return components==1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n),Bob(n);
        int edgeRequired=0;
        for(auto e:edges){
            if(e[0]==3){
                edgeRequired+= (Alice.uni(e[1],e[2]) | Bob.uni(e[1],e[2]));
            }
            // else if(e[0]==1)     edgeRequired+=Alice.uni(e[1],e[2]);
            // else if(e[0]==2)    edgeRequired+=Bob.uni(e[1],e[2]);
        }
        for(auto e:edges){
            if(e[0]==1)     edgeRequired+=Alice.uni(e[1],e[2]);
            else if(e[0]==2)    edgeRequired+=Bob.uni(e[1],e[2]);
        }

        if(Alice.isConnected() && Bob.isConnected()){
            return edges.size()-edgeRequired;
        }
        return -1;
    }
};