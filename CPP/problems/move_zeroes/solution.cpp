class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int j=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0){
	            arr[j++]=arr[i];
	        }
	    }
	    int k=j;
	    for(int i=k;i<n;i++){
	        arr[j++]=0;
	    }
    }
};