class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        int result=0;
        vector<bool> reachableClosedBoxes(status.size(),false);  
        for(int &i:initialBoxes)      
            if(status[i])   q.push(i);
            else    reachableClosedBoxes[i]=true;
        while(!q.empty()){
            result+=candies[q.front()];			
            for(int &i:keys[q.front()]){
                if(!status[i]&&reachableClosedBoxes[i]) q.push(i);
                status[i]=1;
            }
            for(int &i:containedBoxes[q.front()])
                if(status[i])   q.push(i);
                else    reachableClosedBoxes[i]=true;    
            q.pop();
        }
        return result;
    }
};