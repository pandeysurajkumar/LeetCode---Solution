class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int TotalSum = 0;
        for(auto it:nums){
            TotalSum += it;
        }

        int leftSum = 0;

        for(int i=0;i<nums.size();i++){
            
            if(leftSum == TotalSum-leftSum-nums[i]){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};