class Solution {
    bool isvowel(char s)
    {
        return (s == 'a'||s == 'e'||s == 'i'||s == 'o'||s == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int i =0;
        int count = 0;
        int maxi = 0;
        for(int x = 0;x<k;x++)
        {
            if(isvowel(s[x]))
            {
                count++;
            }
        }
        maxi = count;
        for(int x=k;x<s.size();x++)
        {
            if(isvowel(s[x])) count++;
            if(isvowel(s[i]))
            {
                i++;
                count--;
            }
            else{
                i++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};