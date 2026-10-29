class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        for(int i=shifts.length-2;i>=0;i--)
        {
            shifts[i]=(shifts[i]+shifts[i+1])%26;
        }
        int i=0;
        StringBuilder sc = new StringBuilder();
        while(i<shifts.length)
        {
            char ic = s.charAt(i);
            int ip = (int) ic - 'a';
            int np = (ip + shifts[i])%26;
            char nc = (char)(np + 'a');
            sc.append(nc);
            i++;
        }
        return sc.toString();
    }
}