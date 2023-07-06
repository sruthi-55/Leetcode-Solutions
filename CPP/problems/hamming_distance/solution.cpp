class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorr=x^y;
        int c=0;
        while(xorr!=0)
            xorr=xorr&(xorr-1),c++;
        return c;
    }
};