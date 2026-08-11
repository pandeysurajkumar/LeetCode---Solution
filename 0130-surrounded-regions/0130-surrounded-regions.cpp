class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> visited(n, vector<char>(m, '0'));

        queue<pair<int, int>> q;

        // Top row
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O' && visited[0][j] == '0')
            {
                visited[0][j] = '1';
                q.push({0, j});
            }
        }

        // Left column
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && visited[i][0] == '0')
            {
                visited[i][0] = '1';
                q.push({i, 0});
            }
        }

        // Bottom row
        for(int j = 0; j < m; j++)
        {
            if(board[n - 1][j] == 'O' && visited[n - 1][j] == '0')
            {
                visited[n - 1][j] = '1';
                q.push({n - 1, j});
            }
        }

        // Right column
        for(int i = 0; i < n; i++)
        {
            if(board[i][m - 1] == 'O' && visited[i][m - 1] == '0')
            {
                visited[i][m - 1] = '1';
                q.push({i, m - 1});
            }
        }


        // BFS
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if(ni >= 0 && ni < n &&
                   nj >= 0 && nj < m &&
                   board[ni][nj] == 'O' &&
                   visited[ni][nj] == '0')
                {
                    visited[ni][nj] = '1';
                    q.push({ni, nj});
                }
            }
        }


        // Convert surrounded O's to X
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == '0')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};