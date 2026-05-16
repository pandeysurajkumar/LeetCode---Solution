class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {

            int mid = left + (right - left) / 2;

            // Minimum is in right half
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // Minimum can be mid or left half
            else if(nums[mid] < nums[right]) {
                right = mid;
            }

            // Duplicates case
            else {
                right--;
            }
        }

        return nums[left];
    }
};









// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int min = INT_MAX;
//         for(int i =0 ;i<nums.size();i++)
//         {
//             if(nums[i]<min)
//             {
//                 min = nums[i];
//             }
//         }
//         return min;
//     }
// };