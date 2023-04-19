class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        vis[0]=1;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int i=q.front();q.pop();
            for(int key:rooms[i]){
                if(!vis[key]){
                    vis[key]=1;
                    q.push(key);
                }
            }
        }

        for(int i:vis){
            if(!i)  return false; 
        }
        return true;
    }
};