https://leetcode.com/problems/n-queens-ii/submissions/
class Solution {
public:
    
    bool canPlace(vector<string> &board,int row, int col, int n)
    {
        int i,j;
        
        i = row, j = col;
        
        // north west
        while(i>=0 && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        
        // south west
         i = row, j = col;
        while(i<n && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        
        // west
        i = row, j = col;
        while(j>=0)
        {
            if(board[i][j] == 'Q') return false;
            j--;
        }
        
        
        return true;
    }
    
    void solve(vector<string>&board, int col, int &count, int n)
    {
        if(col == n)
        {
            count++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(canPlace(board,i,col,n))
            {
                board[i][col] = 'Q';
                solve(board, col+1, count, n);
                board[i][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        
        
        int count = 0;
        string res = "";
        for(int i=0;i<n;i++) res+='.';
        
        vector<string> board(n,res);
        solve(board, 0, count, n);
        return count;
    }
};

// prb: https://leetcode.com/problems/n-queens-ii/submissions/