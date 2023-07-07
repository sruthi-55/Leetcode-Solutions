class Solution {
public:
    int minBitFlips(int s, int e) {
        int xorr=s^e;
        int c=0;
        while(xorr)
            c+=xorr%2,xorr/=2;
        return c;
    }
};