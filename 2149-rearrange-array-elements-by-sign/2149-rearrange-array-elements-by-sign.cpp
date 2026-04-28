class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int neg = 1;
        int pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg +=2;
                
            }else{
                ans[pos]=nums[i];
                pos +=2;
            }
        }
        return ans;
    }
};