class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int> prev(n2+1,0),cur(n2+1,0);
        
        for(int j=0;j<=n2;j++){
            prev[j]=j;
        }
        for(int i=1;i<=n1;i++){
            cur[0]=i;
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    cur[j]=prev[j-1];
                }
                else{
                    cur[j]=1+min(prev[j],min(cur[j-1],prev[j-1]));
                }
            }
            prev=cur;
        }
        return prev[n2];
    }
};