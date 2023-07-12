class Solution {
public:

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.length();
        int maxi=0;
        int ch[26]={0};
        if(s.length()==0 || maxLetters==0)    return 0;
        unordered_map<string,int> m;
        int letters=0;
        for(int i=0,j=0;i<n;i++){
            if(++ch[s[i]-'a']==1)    letters++;
            while(letters>maxLetters || i-j+1>maxSize){
                if(--ch[s[j]-'a']==0)    letters--;
                j++;
            }
            while(i-j+1>=minSize){
                string cur=s.substr(j,i-j+1);
                m[cur]++;
                maxi=max(maxi,m[cur]);
                if(--ch[s[j]-'a']==0)    letters--;
                j++;
            }
        }
        return maxi;
    }
};
   
      