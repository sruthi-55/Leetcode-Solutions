class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        if(n < 2)
			return n;
        int k=0,c=0;
        for(int i=0,j=i;i<n;){
            c=0;
            while(j<n && chars[i]==chars[j]){
                c++;j++;
            }
            chars[k++]=chars[i];
            if(c>1){
                string str = to_string(c);
				for(auto ch: str)
					chars[k++] = ch;
            }
            i+=c;
        }
        return k;
    }
};