class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum =0;
        int count =0;
        for(auto it:nums)
        {
            sum += it;
            int need = sum -k;
            count += mp[need];
            mp[sum]++;
        }
        return count;
    }
};