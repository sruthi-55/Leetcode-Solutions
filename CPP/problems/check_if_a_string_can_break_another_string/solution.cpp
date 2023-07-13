class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.length();
        int s1Bucket[26]={0};
        int s2Bucket[26]={0};
        for(int i=0;i<n;i++){
            s1Bucket[s1[i]-'a']++;
            s2Bucket[s2[i]-'a']++;
        }
        int count1=0,count2=0;
        bool smallestIsS1=false,smallestIsS2=false;
        for(int i=0;i<26;i++){
            count1 += s1Bucket[i];
            count2 += s2Bucket[i];
            if(count1>count2){
                if(smallestIsS2)    return false;
                smallestIsS1=true;
            }
            else if(count2>count1){
                if(smallestIsS1)    return false;
                smallestIsS2=true;
            }
        }
        return true;
    }
};