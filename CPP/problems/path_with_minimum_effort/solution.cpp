class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>  pq;
        
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dR[]={-1,0,1,0};
        int dC[]={0,1,0,-1};
        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==m-1 && c==n-1)    return diff;
            pq.pop();
            for(int i=0;i<4;i++){
                int neiR=r+dR[i];
                int neiC=c+dC[i];
                if(neiR>=0 && neiC>=0 && neiR<m && neiC<n){
                    int newEffort=max(diff,abs(heights[neiR][neiC]-heights[r][c]));
                    if(newEffort<dist[neiR][neiC]){
                        dist[neiR][neiC]=newEffort;
                        pq.push({newEffort,{neiR,neiC}});
                    }
                }
            }
        }
        return 0;
    }
};