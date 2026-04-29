class Solution {
public:

    void find(int index,int target,vector<int>& candidates,vector<vector<int>> &ans,vector<int> &ds){
        if(index>=candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            find(index,target-candidates[index],candidates,ans,ds);
            ds.pop_back();
        }
        find(index+1,target,candidates,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        find(0,target,candidates,ans,ds);
        return ans;

    }
};