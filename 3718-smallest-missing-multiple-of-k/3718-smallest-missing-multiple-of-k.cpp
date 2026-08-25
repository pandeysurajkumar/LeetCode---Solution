class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        for(int i=1;i<=101;i++)
        {
            int check = k*i;
            if(st.find(check)==st.end())
            {
                return check;
            }
        }
        return 0;
    }
};