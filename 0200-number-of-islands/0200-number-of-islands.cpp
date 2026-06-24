class Solution {
    private:
    vector<vector<int>> possible = {{-1,0},{0,1},{1,0},{0,-1}};
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i ,int j)
    {
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        int row = grid.size();
        int col = grid[0].size();
        q.push({i,j});
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int newp=0;newp<possible.size();newp++)
                {
                    int newi = r + possible[newp][0];
                    int newj = c + possible[newp][1];
                    if(newi >=0 && newj >= 0 && newi < row && newj < col && grid[newi][newj]=='1' && !vis[newi][newj])
                    {
                        vis[newi][newj] = 1;
                        q.push({newi,newj});
                    }
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count=0;
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                        count++;
                        bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};