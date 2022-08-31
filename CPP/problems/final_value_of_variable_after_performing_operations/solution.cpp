class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int y=0;
        for(int i =0; i<op.size(); ++i){   
            
            if(op[i][1]=='+')
                y= y+1;
            else
                y=y-1;
        }
        return y;
    }
};