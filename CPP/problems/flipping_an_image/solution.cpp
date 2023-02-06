class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            int l=0,h=image[0].size()-1;
            while(l<=h){
                if(image[i][l]==image[i][h]){
                    image[i][l] = 1 - image[i][l];
                    image[i][h] = image[i][l];
                }
                l++;h--;
            }
        }
        return image;
    }
};