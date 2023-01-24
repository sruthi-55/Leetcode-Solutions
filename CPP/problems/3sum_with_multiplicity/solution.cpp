class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9+7;
        long ans=0;
        int n=arr.size();
        vector<long> count(101,0);
        for(int x:arr){
            count[x]++;
        }
        //All are different
        for(int x=0;x<=100;x++){
            for(int y=x+1;y<=100;y++){
                int z = target-x-y;
                if(y<z && z<=100){
                    ans+=count[x]*count[y]*count[z];
                    ans%=mod;
                }
            }
        }
        //x==y!=z
        for(int x=0;x<=100;x++){
            int z = target-2*x;
            if(x<z && z<=100){
                ans+=count[x]*(count[x]-1)/2 *count[z];
                ans%=mod;
            }
        }
        //x!=y==z
        for(int x=0;x<=100;x++){
            if(target%2==x%2){
                int y=(target-x)/2;
                if(x<y && y<=100){
                    ans+=count[y]*(count[y]-1)/2 *count[x];
                    ans%=mod;
                }   
            }
        }
        //x==y==z
        if(target%3==0){
            int x=target/3;
            if(0<=x && x<=100){
                ans+=count[x]*(count[x]-1)*(count[x]-2)/6;
                ans%=mod;
            }
        }
        return (int)ans;
    }
};