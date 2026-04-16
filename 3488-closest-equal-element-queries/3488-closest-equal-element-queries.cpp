class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // Store all indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& indices = mp[nums[q]];

            // Only one occurrence
            if (indices.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();

            int prev = indices[(pos - 1 + indices.size()) % indices.size()];
            int next = indices[(pos + 1) % indices.size()];

            int distPrev = min(abs(q - prev), n - abs(q - prev));
            int distNext = min(abs(q - next), n - abs(q - next));

            ans.push_back(min(distPrev, distNext));
        }

        return ans;
    }
};