class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int sum = nums[0];
        int count=0;
        while(right<n){
            while(left<=right && sum >k){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                count++;
            }
            right++;
            if(right<n) sum += nums[right];
        }
        return count;
    }
};