class Solution {
public:
    // bool checkBorder(int i, int j, int row, int col)
    // {
    //     if(i==0 || j == 0 ||  i == row-1 || j == col-1) return true;
    //     else return false;
    // }
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool isSafe(vector<vector<char>>& board, int i, int j, int rows, int cols)
    {
        if (i < 0 or i >= rows or j < 0 or j >= cols or board[i][j] != 'O')
            return false;
        return true;
    }
    
    
    void DFS(vector<vector<char>>& board, int i, int j, const int& rows, const int& cols)
    {
        
        if(!isSafe(board,i,j,rows,cols))
            return;
        
        stack<pair<int,int>>q;
        board[i][j] = 'M';
        q.push({i,j});

        while( !q.empty() )
        {
            auto p = q.top(); q.pop();
            for(int dir = 0; dir<4; dir++)
                if(isSafe(board, p.first + row[dir], p.second+col[dir], rows,cols))
                {
                    board[p.first + row[dir]][p.second + col[dir]] = 'M';
                    q.push({p.first + row[dir], p.second+col[dir]});
                }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        //cout << board[0][0] << endl;
        
//         int i,j;
//         int row = board.size();
//         int col = board[0].size();
        
//         for(i=0;i<row;i++)
//         {
//             for(j=0;j<col;j++)
//             {
//                 if(board[i][j] == 'O' && !checkBorder(i,j,row,col))
//                 {
//                     // if not in border check there exist any border O element
//                     if(board[i-1][j] == 'O' && checkBorder(i-1,j,row,col)) continue;
//                     else if(board[i][j-1] == 'O' && checkBorder(i,j-1,row,col)) continue;
//                     else if(board[i+1][j] == 'O' && checkBorder(i+1,j,row,col)) continue;
//                     else if(board[i][j+1] == 'O' && checkBorder(i,j+1,row,col)) continue;
//                     else board[i][j] = 'X';
//                 }
//             }
//         }
//         for(i=0;i<row;i++)
//         {
//             //cout << "[ ";
//             for(j=0;j<col;j++)
//             {
//                 cout << board[i][j] << " ";
//             }
//             cout << "\n";
//         }
        int rows = board.size();
         if (rows < 1 )
            return;
        int cols = board[0].size();
        
        for(int i=0,j=0,k=cols-1; i<rows;i++)
        {
            if (board[i][j] =='O')
                DFS(board,i,j,rows,cols);
            if (board[i][k] =='O')
                DFS(board,i,k,rows,cols);
        }
        
        //top & bottom
        for(int i=0,k=rows-1,j=0; j<cols;j++)
        {    
            if (board[i][j] =='O')
                DFS(board,i,j,rows,cols);
            if (board[k][j] =='O')
                DFS(board,k,j,rows,cols);
        }
        
        for(int i=0;i < rows; i++)
            for(int j=0;j < cols; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'M')
                    board[i][j] = 'O';
            
        
        
    }
};


/****
 * https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/
 * 
 * **/