class Solution {
public:
    int maxProfit(vector<int> &arr) {
        int n=arr.size();
            if(n==0) return 0;
        vector<int> ahead(2,0),cur(2,0);
        
        ahead[0] = ahead[1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int b=0; b<=1; b++){
                if(b==0)
                    cur[b]=max(0+ahead[0], -arr[i] + ahead[1]);
                if(b==1)
                    cur[b]=max(0+ahead[1], arr[i] + ahead[0]);
            }
            ahead=cur;
        }
        return cur[0];
    }
};