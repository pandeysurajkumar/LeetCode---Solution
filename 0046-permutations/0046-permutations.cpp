class Solution {
private:
    void solve(vector<int>& nums,vector<bool>& visited,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i])
                continue;
            
            visited[i] = true;
            temp.push_back(nums[i]);
            solve(nums,visited,temp,ans);
            temp.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool>visited(n,false);
        solve(nums,visited,temp,ans);
        return ans;
    }
};