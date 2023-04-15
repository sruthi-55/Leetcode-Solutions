class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        vis[0]=1;
        stack<int> s;
        s.push(0);

        while(!s.empty()){
            int i=s.top();s.pop();
            for(int key:rooms[i]){
                if(!vis[key]){
                    vis[key]=1;
                    s.push(key);
                }
            }
        }

        for(int i:vis){
            if(!i)  return false; 
        }
        return true;
    }
};