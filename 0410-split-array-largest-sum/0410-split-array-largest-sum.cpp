class Solution {

    bool isPossible(vector<int>& nums,int n, int k,int mid){
        if(k>n) return false;
        int studentCount = 1;
        long long pageSum =0;
        for(int i=0;i<n;i++){
            if(pageSum+nums[i]<=mid){
                pageSum += nums[i];
            }
            else{
                studentCount++;
                if(studentCount>k||nums[i]>mid){
                    return false;
                }
                pageSum = nums[i];
            }
        }
        return true;
    }


public:
    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        long long totalSum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        long long end = totalSum;
        int ans = -1;
        while(s<=end){
            int mid = s + (end-s)/2;

            if(isPossible(nums,n,k,mid)){
                ans = mid;
                end = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};