class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        {
            return "";
        }
        string ans = "";

        // take char of first word for compair
        for(int i=0;i<strs[0].size();i++)
        {
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(i>=strs[j].size())
                {
                    return ans;
                }
                if(ch != strs[j][i])
                {
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
    }
};