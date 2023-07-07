class Solution {
public:
    int minimizeXor(int a, int b) {
        int totalSetinB=0;
        while(b){
            totalSetinB+= b%2,b/=2;
        }
        int x=0;
        //if set in a, we set it in x also
        for(int i=31;i>=0 && totalSetinB;i--){
            if(a&(1<<i)){
                x|=(1<<i);
                totalSetinB--;
            }    
        }
        //set remaining bits from the LSB positions
        for(int i=0;i<=31 && totalSetinB;i++){
            if((x&(1<<i))==0){
                x|=(1<<i);
                totalSetinB--;
            }
        }
        return x;
    }
};