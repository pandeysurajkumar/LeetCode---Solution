class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<vector<int>> que;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    que.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }

        vector<vector<int>> possible = {{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<int>> result(n,vector<int>(m,0));
        while(!que.empty())
        {
            int i = que.front()[0];
            int j = que.front()[1];
            int dis = que.front()[2];
            result[i][j] = dis;
            que.pop();
            for(int k = 0;k<possible.size();k++)
            {
                int newi = i + possible[k][0];
                int newj = j + possible[k][1];
                if(newi >= 0 && newi < n && newj >= 0 && newj < m && visited[newi][newj] != 1)
                {
                    que.push({newi,newj,dis+1});
                    visited[newi][newj] = 1;
                }

            }
        }
        return result;

    }
};