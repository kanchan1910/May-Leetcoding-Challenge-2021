class Solution {
public:
    bool isSafe(vector<vector<int>>&board, int row, int col, int n)
    {
        // checking for upper column
        int x = 0, y = col;
        while(x < row)
        {
            if(board[x][y] == 1)
            {
                return false;
            }
            x++;
        }
        // checking for left diagonal
        x = row - 1, y = col - 1;
        while(x >= 0 && y >= 0)
        {
            if(board[x][y] == 1)
            {
                return false;
            }
            x--;
            y--;
        }
        // checking for right daigonal
        x = row - 1, y = col + 1;
        while(x >= 0 && y < n)
        {
            if(board[x][y] == 1)
            {
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    bool solve(vector<vector<int>>&board,  vector<vector<string>>&ans, int n, int row)
    {
        // base case
        // we have reached the row = n, means at all the rows we have successfully places the queens 
        if(row == n)
        {
            vector<string>tmp;
            for(int i = 0; i < n; i++)
            {
                string str = "";
                for(int j = 0; j < n; j++)
                {
                    if(board[i][j] == 1)
                    {
                        str += "Q";
                    }
                    else
                    {
                        str += ".";
                    }
                }
                tmp.push_back(str);
            }
            ans.push_back(tmp);
            // if we return true here then only the first arrangement will be returned as our answer, but we want all the arrangements so, we will return false, so that it backtrack again and we can get the another arranegment if excisting 
            return false;
        }
        // checking each column the the current row
        for(int col = 0; col < n; col++)
        {
            // if the position is safe
            if(isSafe(board, row, col, n) == true)
            {
                // put the queen here
                board[row][col] = 1;
                // and recursion will check for the final state by soing the same recursively
                bool kyaAageQueensRkhPaRheHai = solve(board, ans, n, row + 1);
                // if it works fine, then return true
                if(kyaAageQueensRkhPaRheHai == true)
                {
                    return true;
                }
                // else backtrack
                board[row][col] = 0;
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // empty chess board
        vector<vector<int>>board(n, vector<int>(n, 0));
        // answer vector after placing queens
        vector<vector<string>>ans;
        // this function will return all the possible arrangements if possible
        bool val = solve(board, ans, n, 0);
        // finally, return the answer vector
        return ans;
    }
};
