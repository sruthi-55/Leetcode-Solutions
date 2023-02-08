class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(), n=box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for(int r=0;r<m;r++){
            for(int emp=n-1,k=n-1;emp>=0;emp--){
                if (box[r][emp] != '.'){
                    k = box[r][emp]=='*' ? emp : k;

                    res[k][m-r-1]=box[r][emp];
                    k--;
                }   
            }
        }
        return res;
    }
};