class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<int> front(n,0);
        //base case
        for(int j=0;j<=n-1;j++){
            front[j]=t[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> cur(n,0);
            for(int j=0;j<=i;j++){
                int d1=t[i][j]+front[j];
                int d2=t[i][j]+front[j+1];
                cur[j]=min(d1,d2);
            }
            front=cur;
        }
        return front[0];
    }
};