class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int preff = 1;
        int suff = 1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(preff == 0) preff = 1;
            if(suff == 0) suff = 1;
            preff = preff * nums[i];
            suff = suff * nums[n-i-1];
            ans = max(ans,max(preff,suff));
        }
        return ans;
    }
};