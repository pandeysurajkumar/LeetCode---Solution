class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if(k>s2.size())return false;
        unordered_map<char,int> s1map;
        unordered_map<char,int> s2map;

        for(char c:s1)
        {
            s1map[c]++;
        }
        // first window
        for(int i=0;i<k;i++)
        {
            s2map[s2[i]]++;
        }
        if(s1map == s2map) return true;

        // slide the window
        for(int i=k;i<s2.size();i++)
        {
            char add = s2[i]; 
            s2map[add]++;
            char remove = s2[i-k];
            s2map[remove]--;
            if(s2map[remove]==0){
                s2map.erase(remove);
            }
            if(s1map == s2map) return true;
        }
        return false;
    }
};