class Solution {
public:

    void permu(vector<int>& nums,
               vector<bool>& used,
               vector<vector<int>>& ans,
               vector<int>& dp){

        // Base condition
        if(dp.size() == nums.size()){
            ans.push_back(dp);
            return;
        }

        for(int i=0; i<nums.size(); i++){

            // Skip used element
            if(used[i]) continue;

            used[i] = true;
            dp.push_back(nums[i]);

            permu(nums, used, ans, dp);

            // Backtrack
            dp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> dp;
        vector<bool> used(nums.size(), false);

        permu(nums, used, ans, dp);

        return ans;
    }
};