class Solution {

        void permu(int index,vector<int>& nums,
               vector<vector<int>>& ans){

                if(index == nums.size())
                {
                    ans.push_back(nums);
                    return;
                }
                for(int i=index;i<nums.size();i++)
                {
                    swap(nums[index],nums[i]);
                    permu(index+1,nums,ans);
                    // Backtracking
                    swap(nums[index],nums[i]);
                }

               }


public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permu(0,nums,ans);
        return ans;
    }
};















// class Solution {
// public:

//     void permu(vector<int>& nums,
//                vector<bool>& used,
//                vector<vector<int>>& ans,
//                vector<int>& dp){

//         // Base condition
//         if(dp.size() == nums.size()){
//             ans.push_back(dp);
//             return;
//         }

//         for(int i=0; i<nums.size(); i++){

//             // Skip used element
//             if(used[i]) continue;

//             used[i] = true;
//             dp.push_back(nums[i]);

//             permu(nums, used, ans, dp);

//             // Backtrack
//             dp.pop_back();
//             used[i] = false;
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {

//         vector<vector<int>> ans;
//         vector<int> dp;
//         vector<bool> used(nums.size(), false);

//         permu(nums, used, ans, dp);

//         return ans;
//     }
// };