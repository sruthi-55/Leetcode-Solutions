class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> m;
        int res=0;
        for(int i:ages){
            m[i]++;
        }
        for(auto i:m){
            for(auto j:m){
                if(request(i.first,j.first)){
                    res+=i.second*(j.second-(i.first==j.first?1:0));
                }
            }
        }
        return res;
    }
    bool request(int a,int b){
        return !(b<=0.5*a+7 || b>a || (b>100 && a<100));
    }
};