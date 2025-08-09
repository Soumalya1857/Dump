 // soln: https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=59
 // prb: https://leetcode.com/problems/n-queens/


 // try to fill each column and when we cannot fill a column we just backtrack and delete the already placed queens

 class Solution {
public:
    bool canFill(vector<string>&board, int row, int col, int n)
    {
        // no need to check the right half
        // col eo ekbar e check as up to down aschi amra
        
        int i,j;
        
        
//         for(int j=0;j<col;j++) 
//             if(board[row][j] == 'Q') return false;
        
//         for(int i=0;i<n;i++)
//             if(board[i][col] == 'Q') return false;
        
        // int i=row, j=col;
        // while(i<n && j<n)
        // {
        //     if(board[i][j] == 'Q') return false;
        //     i++;
        //     j++;
        // }
        
        i=row, j=col; // needed North East
        while(i>=0 && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        
        i=row, j=col;
        while(j>=0) // needed east
        {
            if(board[i][j] == 'Q') return false;
            j--;
        }
        
        i=row, j=col; // needed south east
        while(i<n && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        
        // while(i>=0 && j<n)
        // {
        //     if(board[i][j] == 'Q') return false;
        //     i--;
        //     j++;
        // }
        
        return true;
    }
    
    void solve(int col, vector<string>&board, vector<vector<string>>&ans,int n)
    {
        if(col == n) {
            ans.push_back(vector<string>(board));
            return;
        }
        
        for(int row = 0; row<n;row++)
        {
            if(canFill(board, row, col,n))
            {
                board[row][col] = 'Q';
                solve(col+1, board, ans,n);
                board[row][col] = '.'; // backtrack step bro
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        string res = "";
        for(int i=0;i<n;i++) res+='.';
        vector<string>board(n);
        for(int i=0;i<n;i++) board[i] = res;
        vector<vector<string>>ans;
        
        
        solve(0,board,ans,n);
        return ans;
        
        
    }
};