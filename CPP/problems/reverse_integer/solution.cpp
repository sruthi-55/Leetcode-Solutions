class Solution {
public:
    int reverse(int n) {
        int num=n;
        int rev=0;
        while(num){
            if(rev>INT_MAX/10 || rev<INT_MIN/10) return 0;
            int d=num%10;
            rev=rev*10+d;
            num/=10;
        }
        return rev;
    }
};