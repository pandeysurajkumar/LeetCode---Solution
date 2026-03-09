class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second == 1){
                sum = sum+it.first;
            }
        }
        return sum;
    }
};