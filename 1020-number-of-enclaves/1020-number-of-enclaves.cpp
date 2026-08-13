class Solution {

public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>& visited,int delr[],int delc[])
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = -1;
        for(int k=0;k<4;k++)
        {
            int newr = i + delr[k];
            int newc = j + delc[k];
            if(newr >= 0 && newc >= 0 && newr < n && newc < m && visited[newr][newc] != -1 && grid[newr][newc] == 1)
            {
                dfs(newr,newc,grid,visited,delr,delc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(grid.begin(),grid.end());
        int delr[] = {0,1,0,-1};
        int delc[] = {1,0,-1,0};
        // first row
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1 && visited[0][j] ==1)
            {
                dfs(0,j,grid,visited,delr,delc);
            }
        }
        // first col
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && visited[i][0] ==1)
            {
                dfs(i,0,grid,visited,delr,delc);
            }
        }
        // last row
        for(int j=0;j<m;j++)
        {
            if(grid[n-1][j]==1 && visited[n-1][j] ==1)
            {
                dfs(n-1,j,grid,visited,delr,delc);
            }
        }
        // last col
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1 && visited[i][m-1] ==1)
            {
                dfs(i,m-1,grid,visited,delr,delc);
            }
        }

        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};