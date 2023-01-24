class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            int b=c-i*i;
            if(binary_search(0,b,b))    return true;
        }
        return false;
    }
    bool binary_search(long s,long e,long a){
        if(s>e) return false;
        long mid=s+(e-s)/2;
        if(mid*mid==a)  return true;
        else if(mid*mid>a)  return binary_search(s,mid-1,a);
        return binary_search(mid+1,e,a);

    }
};