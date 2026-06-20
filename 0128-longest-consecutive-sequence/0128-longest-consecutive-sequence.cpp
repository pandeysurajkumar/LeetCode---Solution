class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size()-1;
        int longest = 0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int current = it;
                int count = 1;
                while(st.find(current+1)!=st.end())
                {
                    current++;
                    count++;
                }
                longest = max(longest,count);
            }
        }
        return longest;

    }
};