class Solution {
    public boolean isPalindrome(String s) {
        int h=0,t=s.length()-1;
        char ch,ct;
        if(s.isEmpty()){
            return true;
        }

        while(h<=t){
            ch=s.charAt(h);
            ct=s.charAt(t);
            if(!Character.isLetterOrDigit(ch))   h++;
            else if(!Character.isLetterOrDigit(ct))  t--;
            else{
                if(Character.toLowerCase(ch)!=Character.toLowerCase(ct)){
                    return false;
                }  
                h++;t--;
            }
            
        }
        return true;
    }
}