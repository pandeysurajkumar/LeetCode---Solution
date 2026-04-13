// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int>freq;
//         for(auto it:nums){
//             freq[it]++;
//         }
//         for(auto it:freq){
//             if(it.second != 1){
//                 return true;
//             }
//         }
//         return false;

//     }
// };









class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums){
            if(s.count(it)) return true;
            s.insert(it);
        }
        return false;
    }
};





// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         set<int> s(nums.begin(),nums.end());
//         if(s.size()!= nums.size()) return true;
//         return false;
//     }
// };