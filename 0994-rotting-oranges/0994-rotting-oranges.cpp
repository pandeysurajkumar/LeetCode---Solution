class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countfresh = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }else if(grid[i][j]==1)
                {
                    countfresh++;
                    visited[i][j]=1;
                }else
                {
                    visited[i][j]=0;
                }
            }
        }
        if(countfresh == 0) return 0;
        int maxTime = 0;
        int count = 0;
        vector<pair<int,int>> possible = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            maxTime = max(maxTime,t);
            for(auto &it:possible)
            {
                int nr = it.first + r;
                int nc = it.second + c;
                if(nr >= 0 && nc >= 0 && nr < n && nc  < m && visited[nr][nc] != 2 && grid[nr][nc] == 1)
                {
                    q.push({{nr,nc},t+1});
                    visited[nr][nc] = 2;
                    count++;
                }
            }
        }
        if(count != countfresh) return -1;
        return maxTime;
    }
};