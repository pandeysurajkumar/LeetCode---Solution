class Solution {
public:
    vector<int> row(int r)
    {
        long long an = 1;
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<r;i++)
        {
            an = an *(r-i);
            an = an/i;
            ans.push_back(an);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 1;i<=numRows;i++)
        {
            result.push_back(row(i));
        }
        return result;
    }
};