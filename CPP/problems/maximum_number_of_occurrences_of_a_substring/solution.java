class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int[] ch = new int[26];
        int Letters=0,NoOfOccurrence=0;
        Map<String,Integer> map = new HashMap<>();
        for(int i=0,j=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(++ch[c-'a']==1) {
                Letters++;
            }
            while(Letters>maxLetters || i-j+1>maxSize) {
                if(--ch[s.charAt(j)-'a']==0) Letters--;
                j++;
            }
            while(i-j+1>=minSize) {
                String s1=s.substring(j,i+1);
                map.put(s1,map.getOrDefault(s1,0)+1);
                NoOfOccurrence=Math.max(NoOfOccurrence,map.get(s1));
                if(--ch[s.charAt(j)-'a']==0) Letters--;
                j++;
            }
        }
        return NoOfOccurrence;
    }
}