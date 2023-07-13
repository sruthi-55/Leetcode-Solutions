class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> m=new HashMap<>();
        int n=s.length();
        for(int i=0;i<n;i++){
            char charS=s.charAt(i);
            char charT=t.charAt(i);
            if(m.containsKey(charS)){
                if(m.get(charS)!=charT) return false;
            } 
            else{
                if(m.containsValue(charT))  return false;
                m.put(charS,charT);
            } 
        }
        return true;
    }
}