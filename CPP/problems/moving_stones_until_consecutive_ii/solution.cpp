class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        int n=A.size();
        sort(A.begin(),A.end());
        int high=max( A[n-1]-A[1]-n+2, A[n-2]-A[0]-n+2);
        int low=n;int i,j;
        for(i=0,j=0;j<n;j++){
            while(A[j]-A[i]+1>n)    i++;
            int already_store=j-i+1;
            if(already_store==n-1 && A[j]-A[i]+1==n-1){
                low=min(low,2);
            }
            else{
                low = min(low,n-already_store);
            }
        }
        return {low,high};
    }
};