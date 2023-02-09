class Solution {
public:
    int magicalString(int n) {
        vector<int> A(n+1);
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        A[0]=1,A[1]=2,A[2]=2;
        int h=2,t=3;
        int num=1;
        int res=1;
        while(t<n){
            for(int i=0;i<A[h];i++){
                A[t]=num;
                if(A[t]==1 && t<n) res++;
                t++;
            }
            num=3-num;
            h++;
        }
        return res;
    }
};