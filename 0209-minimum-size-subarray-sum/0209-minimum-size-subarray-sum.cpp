class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n= nums.size();
        int minlength = INT_MAX;
        int sum  = 0;
        while(j<n)
        {
            sum += nums[j];
            while(sum >= target)
            {
                int len = (j-i)+1;
                minlength = min(minlength,len);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        return (minlength == INT_MAX) ? 0 : minlength;
    }
};