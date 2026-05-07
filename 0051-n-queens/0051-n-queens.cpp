class Solution {
public:
    void place(int col,vector<string> &board,
            vector<vector<string>> &ans,
            vector<int> &upper,
            vector<int> &left,
            vector<int> &down,
            int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(upper[n-1 + (col-row)] == 0 && left[row] == 0 && down[row+col] == 0)
            {
                board[row][col] = 'Q';
                upper[n-1+(col-row)] = 1;
                left[row] = 1;
                down[row+col] = 1;
                place(col+1,board,ans,upper,left,down,n);
                board[row][col] = '.';
                upper[n-1 + (col-row)] = 0;
                left[row] = 0;
                down[row+col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        vector<int>upper(2*n-1,0);
        vector<int>left(n,0);
        vector<int>down(2*n-1,0);
        place(0,board,ans,upper,left,down,n);
        return ans;
    }
};












// class Solution {
// public:
//     bool isSafe(int row,int col,vector<string> board,int n)
//     {
//         int rowStore = row;
//         int colStore = col;

//         // for upper
//         while(row >= 0 && col >= 0)
//         {
//             if(board[row][col]=='Q') return false;
//             row--;
//             col--;
//         }

//         // for back
//         row = rowStore;
//         col = colStore;
//         while(col >= 0)
//         {
//             if(board[row][col]=='Q') return false;
//             col--;
//         }

//         // for down
//         row = rowStore;
//         col = colStore;
//         while(row<n && col >= 0)
//         {
//             if(board[row][col]=='Q') return false;
//             row++;
//             col--;
//         }

//         return true;
//     }



//     void place(int col,vector<string> &board,vector<vector<string>> &ans,int n)
//     {
//         if(col == n)
//         {
//             ans.push_back(board);
//             return;
//         }

//         for(int row=0;row<n;row++)
//         {
//             if(isSafe(row,col,board,n))
//             {
//                 board[row][col] = 'Q';
//                 place(col+1,board,ans,n);
//                 board[row][col] = '.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++)
//         {
//             board[i] = s;
//         }
//         place(0,board,ans,n);
//         return ans;
//     }
// };