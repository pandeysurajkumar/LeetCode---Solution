class Solution {
    public int characterReplacement(String s, int k) {
        int i =0;
        int j = 0;
        int maxf = 0;
        int maxl = 0;
        int hash[] = new int[26];
        while(j<s.length())
        {
            maxf = Math.max(maxf,++hash[s.charAt(j)-'A']);
            if((j-i+1)-maxf > k)
            {
                hash[s.charAt(i)-'A']--;
                i++;
            }
            if((j-i+1)-maxf <= k)
            {
                maxl = Math.max(maxl,j-i+1);
            }
            j++;
        }
        return maxl;
    }
}