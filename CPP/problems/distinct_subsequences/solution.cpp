class Solution {
public:
    int numDistinct(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<double> prev(n2+1,0);
        for(int i=0;i<=n1;i++){
            prev[0]=1;
        }
        for(int i=1;i<=n2;i++){
            prev[i]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=n2;j>=1;j--){ // Reverse direction
                if(s1[i-1]==s2[j-1])
                    prev[j] = prev[j-1] + prev[j];
            }
        }

        return (int)prev[n2];
    }
};