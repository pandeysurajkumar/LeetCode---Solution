class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                count++;
            }
            else if(count == 0){
                ele = nums[i];
                count++;
            }else{
                count--;
            }
        }
        int count1=0;
        for(auto it:nums){
            if(it == ele) count1++;
        }
        if(count1>nums.size()/2){
            return ele;
        }
        return -1;
    }
    
};