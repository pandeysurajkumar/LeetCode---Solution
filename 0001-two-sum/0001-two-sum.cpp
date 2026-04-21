class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ReqSum;
        for(int i=0;i<nums.size();i++){
            int req = target-nums[i];
            if(ReqSum.find(req)!=ReqSum.end()){
                return {i,ReqSum[req]};
            }
            ReqSum[nums[i]] = i;
        }
        return{};
    }
};