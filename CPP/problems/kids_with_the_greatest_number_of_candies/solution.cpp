#include<bits/stdc++.h>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size());
        
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=*max_element(candies.begin(),candies.end())){
                res[i]=true;
            }
            else
                res[i]=false;
        }
        return res;
    }
};