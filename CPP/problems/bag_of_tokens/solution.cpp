class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int points=0,score=0;
        sort(tokens.begin(),tokens.end());
        int l=0,h=tokens.size()-1;
        while(l<=h && (tokens[l]<=power || points>0)){
            while(l<=h && tokens[l]<=power){
                power-=tokens[l++];
                points++;
            }
            score= max(score,points);
            if(l<=h && points>0){
                points--;
                power+=tokens[h--];
            }
        }
        return score;
    }
};