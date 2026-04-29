class Solution {
public:

    void find(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>&dp){
        
        ans.push_back(dp);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            dp.push_back(nums[i]);
            find(i+1,nums,ans,dp);
            dp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>dp;
        find(0,nums,ans,dp);
        return ans;
    }
};