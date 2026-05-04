class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());  // STL Library for next_permutation i.e.Better solution

        int index = -1;
        int n = nums.size();

        //find break point
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
           return;
        }

        // find min and swap
        for(int i = n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        // reverse rest of it
        reverse(nums.begin()+index+1,nums.end());

        
    }
};