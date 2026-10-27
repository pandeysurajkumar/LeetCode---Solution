class Solution {
    public String longestPalindrome(String s) {
        int start = 0;
        int maxl = 0;
        for(int i=0;i<s.length();i++)
        {
            // for odd
            int left =i;
            int right = i;
            while(left>=0 && right < s.length() && s.charAt(left)==s.charAt(right))
            {
                int len = right-left+1;
                if(len > maxl){
                    maxl = len;
                    start = left;
                }
                left --;
                right++;
            }
            // for even
             left =i;
             right = i+1;
            while(left>=0 && right < s.length() && s.charAt(left)==s.charAt(right))
            {
                int len = right-left+1;
                if(len > maxl){
                    maxl = len;
                    start = left;
                }
                left --;
                right++;
            }
        }
        return s.substring(start,start+maxl);
    }
}