class Solution {
public:

    void permu( vector<int>& nums,vector<bool>& used,vector<vector<int>>& ans,vector<int>& dp){
        // base condition
        if(dp.size()==nums.size()){
            ans.push_back(dp);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i]=true;
            dp.push_back(nums[i]);
            permu(nums,used,ans,dp);
            dp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int>dp;
        vector<bool> used(n,false);
        permu(nums,used,ans,dp);
        return ans;
    }
};