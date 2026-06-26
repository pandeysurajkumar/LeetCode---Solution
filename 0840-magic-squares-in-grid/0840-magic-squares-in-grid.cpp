class Solution {
private:
    bool ismagic(vector<vector<int>>& grid,int r,int c)
    {
        vector<bool> visited(10,false);
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                int item = grid[i][j];
                if(item<1 ||item > 9) return false;
                if(visited[item]) return false;
                visited[item] = true;
            }
        }
        int target = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        //check for row
        for(int i=0;i<3;i++)
        {
            int sum  = 0;
            for(int j=0;j<3;j++)
            {
                sum += grid[r+i][j+c];
            }
            if(sum!=target) return false;
        }
        //check for col
        for(int j=0;j<3;j++)
        {
            int sum = 0;
            for(int i=0;i<3;i++)
            {
                sum += grid[r+i][c+j];
            }
            if(sum != target) return false;
        }
        //first diogal 
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] != target) return false;
        // second diagonal
        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c] != target) return false;
        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                if(ismagic(grid,i,j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};