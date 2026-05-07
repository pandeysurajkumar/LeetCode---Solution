class Solution {
public:

    void permu(vector<int>& nums,
               vector<bool>& used,
               vector<vector<int>>& ans,
               vector<int>& dp){

        // Base case
        if(dp.size() == nums.size()){
            ans.push_back(dp);
            return;
        }

        for(int i=0; i<nums.size(); i++){

            // Skip already used elements
            if(used[i]) continue;

            // Skip duplicates
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            used[i] = true;
            dp.push_back(nums[i]);

            permu(nums, used, ans, dp);

            dp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> dp;
        vector<bool> used(nums.size(), false);

        permu(nums, used, ans, dp);

        return ans;
    }
};