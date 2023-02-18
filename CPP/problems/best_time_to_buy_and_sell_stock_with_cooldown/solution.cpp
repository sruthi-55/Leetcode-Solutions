class Solution {
public:
    int maxProfit(vector<int> &arr) {
        int n=arr.size();
        vector<int> cur(2,0);
        vector<int> front1(2,0);
        vector<int> front2(2,0);
        
        for(int i = n-1; i>=0; i--){
            for(int b=0; b<=1; b++){
                if(b==0){// We can b the stock
                    cur[b] = max(0+front1[0], -arr[i] + front1[1]);
                }
                if(b==1){// We can sell the stock
                    cur[b] = max(0+front1[1], arr[i] + front2[0]);
                }
            }
            front2 = front1;
            front1 = cur;
        }
        return cur[0];
    }  
};