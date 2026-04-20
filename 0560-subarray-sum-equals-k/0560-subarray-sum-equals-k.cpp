class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;        // ✅ changed from maxLen
        long long sum = 0;

        unordered_map<long long, int> prefixsum;

        prefixsum[0] = 1;     // ✅ IMPORTANT (handle sum == k)

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            long long rem = sum - k;

            // ✅ check how many times rem appeared
            if(prefixsum.find(rem) != prefixsum.end()) {
                count += prefixsum[rem];
            }

            // ✅ store frequency (not index)
            prefixsum[sum]++;
        }

        return count;
    }
};