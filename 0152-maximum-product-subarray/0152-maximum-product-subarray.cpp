class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpod = nums[0];
        int minpod = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(maxpod,minpod);
            }
            maxpod = max(nums[i],maxpod*nums[i]);
            minpod = min(nums[i],minpod*nums[i]);
            ans = max(maxpod,ans);
        }
        return ans;
    }
};