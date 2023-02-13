class Solution {
public:
    int fib(int n){
        if(n == 0 || n == 1) return n;
        int prev2=0,prev=1;
        int cur=0;
        for(int i=2;i<=n;i++){
            cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }   
        return prev;

    }
};