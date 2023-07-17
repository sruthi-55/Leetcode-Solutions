class Solution {
public:
    string nearestPalindromic(string n) {
        //if single digit
        if(n.length()==1)   return to_string(stoi(n)-1);
        int digits=n.length();
        vector<long> candidates;
        //4723. digits=4
        //candidates-- 999,10001
        candidates.push_back(pow(10,digits-1)-1);       //Case 1: one digit less
        candidates.push_back(pow(10,digits)+1);      //Case 2: one digit more
        //Case 3: same no of digits
        int mid=(digits+1)/2;   //mid=2
        long prefix=stol(n.substr(0,mid));      //47
        vector<long> v= {prefix,prefix+1,prefix-1}; //47,48,46
        for(long i:v){
            string prefS=to_string(i);      //47
            if(digits%2!=0)     prefS.pop_back();   //47
            reverse(prefS.begin(),prefS.end());     //74
            string c= to_string(i)+prefS;    //47+74
            candidates.push_back(stol(c));
        }
        //47678 digits=5
        //candidates-- 9999,100001
        //mid=3
        //prefix-- 476 477 475
        //rev(47 47 47) --- 74, 74, 74
        //47674, 47774, 47574

        //4723. digits=4
        //candidates-- 999,10001
        //mid=2
        //prefix-- 47,48,46
        //rev-- 74,84,64
        //4774, 4884, 4664
        
        long minDiff=LONG_MAX;
        long res; long num=stol(n);
        //total candidates are 5
        for(int i=0;i<5;i++){
            if(candidates[i]!=num && abs(candidates[i]-num)<minDiff){
                minDiff=abs(candidates[i]-num);
                res=candidates[i];
            }
            else if(abs(candidates[i]-num)==minDiff)    res=min(res,candidates[i]);
        }
        return to_string(res);
    }
};