class Solution {
    
    private:
    
        vector<vector<bool>> grid;
        vector<vector<bool>> rows;
        vector<vector<bool>> cols;
        vector<vector<char>> board;
        int filled;
    
    public:
    
        int gridpos(int i, int j)
        {
            return (3*(i/3)) + (j/3);
        }
    
        void fill(int i, int j, char c)
        {
            board[i][j] = c;
            grid[gridpos(i, j)][c - '1'] = true;
            rows[i][c - '1'] = true;
            cols[j][c - '1'] = true; 
            filled += 1;
        }
    
        void unfill(int i, int j, char c)
        {
            board[i][j] = '.';
            grid[gridpos(i, j)][c - '1'] = false;
            rows[i][c - '1'] = false;
            cols[j][c - '1'] = false; 
            filled -= 1;
        }
    
        bool isvalid(int i, int j, char c)
        {
            return (!(grid[gridpos(i, j)][c - '1'] ||
            rows[i][c - '1'] ||
            cols[j][c - '1']));          
        }
    
        void solveSudoku(vector<vector<char>>& b) {
            
            filled = 0;
            // this just creates a copy not a actual reference
            board = b;
            grid = vector<vector<bool>>(9, vector<bool>(9, false));
            rows = vector<vector<bool>>(9, vector<bool>(9, false));
            cols = vector<vector<bool>>(9, vector<bool>(9, false));
            
            char c;
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    if ((c = board[i][j]) != '.')
                        fill(i, j, c);
                    
               
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    if (board[i][j] == '.')
                        if (solve())
                        {
                            for(int ii = 0; ii < 9; ii++)
                                for(int jj = 0; jj < 9; jj++)
                                    b[ii][jj] = board[ii][jj];
                            return;
                        }
                        
        }

        bool solve()
        {
            /*
            Find the first unfilled spot and try to fill it,
            if it can be filled recurse.

            If filled becomes 81 we found the solution.

            If not the sudoku can't be filled in this state. Go back.
                The state the board is in the first free spot wont be ever able to be filled
                if it can't be filled at the start.
            */
            for (int i1 = 0; i1 < 9; i1++)
                for (int j1 = 0; j1 < 9; j1++)
                    if (board[i1][j1] == '.')
                    {
                        for (char c = '1'; c <= '9'; c++)
                        {
                            if (isvalid(i1, j1, c))
                            {
                                fill(i1, j1, c);
                                
                                if (filled == 81 || solve())
                                    return true;

                                unfill(i1, j1, c);
                            }
                        }
            // If after filling that spot with all possible numbers the sudoku still 
            // hasnt found a solution
            // we need to return false here and exit from this call.
            // the reason why is that this means the previous calls that resulted in us being here
            // resulted in a board state impossible to solve and we need to go back to those
            // previous calls and fix the situation we are in.
            // otherwise eventually we will get back to this cell and it still won't be able to be filled
            // the return false here instead of trying to find the next spot to fill ends a lot of the bad
            // search paths early since if a spot is impossible to fill right now it will always be impossible to fill
            // so the previous actions that got us here need to be remedied
                        return false;
                    }
            // solution will be found before here
            // put to shut up the compiler
            return true;
        }
};

// question: https://leetcode.com/problems/sudoku-solver