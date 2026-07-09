class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> fre;
        for(auto it:nums)
        {
            fre[it]++;
        }
        int maxfre = 0;
        for(auto it:fre)
        {
            maxfre = max(maxfre,it.second);
        }
        int sum = 0;
        for(auto it:fre)
        {
            if(it.second == maxfre) sum += it.second;
        }
        return sum;
    }
};