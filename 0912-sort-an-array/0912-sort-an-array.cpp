class Solution {
public:

    
    void merge(vector<int> &nums,int low,int mid,int high){
        vector<int> res;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                res.push_back(nums[left]);
                left++;
            }
            else{
                res.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            res.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            res.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]= res[i-low];
        }
    }
    void ms(vector<int> &nums,int low,int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        ms(nums,low,mid);
        ms(nums,mid+1,high);
        merge(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
       ms(nums,0,nums.size()-1); 
       return nums;
    }
};