class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n!=0){
            int rem=n%26;
            if(rem==0){
                ans='Z'+ans;
                n=n/26-1;
            }
            else{
                char c='A'+rem-1;
                ans=c+ans;
                n/=26;
            }
        }
        return ans;
    }
};