class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i= 0;
        int j =0 ;
        int n = s.size();
        vector<int> hash(256,-1);
        int maxlen = 0;
        while(j<n)
        {
            if(hash[s[j]] != -1)
            {
                if(hash[s[j]] >= i)
                {
                    i = hash[s[j]]+1;
                }
            }
            int len = j-i+1;
            maxlen = max(maxlen,len);
            hash[s[j]] = j;
            j++;
        }
        return maxlen;
    }
};