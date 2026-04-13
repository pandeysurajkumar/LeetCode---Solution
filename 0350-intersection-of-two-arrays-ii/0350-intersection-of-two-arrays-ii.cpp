class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int size1  = nums1.size();
        int size2  = nums2.size();

        int left = 0;
        int right = 0;
        vector<int> result;
        while(left<size1 &&  right  < size2){
            if(nums1[left]==nums2[right]){
                result.push_back(nums1[left]);
                left++;
                right++;
            }else{
                if(nums1[left]<nums2[right]){
                    left++;
                }else{
                    right++;
                }
            }
        }
        return result;
        
    }
};