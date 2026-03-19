class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};










// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int k=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=0){
//                 nums[k]=nums[i];
//                 k++;
//             }
//         }
//         if(k<nums.size()){
//             while(k<nums.size()){
//                 nums[k]=0;
//                 k++;
//             }
//         }
//     }
// };