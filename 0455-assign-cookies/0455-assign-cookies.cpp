class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = s.size();
        int i =0;
        int j = 0;
        while(i<n && j < g.size())
        {
            if(s[i] >= g[j])
            {
                j++;
            }
            i++;
        }
        return j;
    }
};