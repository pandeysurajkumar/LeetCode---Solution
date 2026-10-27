class Solution {
    public int countword(String s)
    {
        String[] words = s.trim().split("\\s+");
        return words.length;
    }

    public int mostWordsFound(String[] sentences) {
        int maxl = 0;
        for(int i=0;i<sentences.length;i++)
        {
            int count = countword(sentences[i]);
            maxl = Math.max(maxl,count);
        }
        return maxl;
    }
}