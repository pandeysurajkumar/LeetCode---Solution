class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(auto it: nums)
        {
            total += it;
        }
        int left =0 ;
        for(int i=0;i<nums.size();i++)
        {
            if(left == total - nums[i]-left)
            {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};