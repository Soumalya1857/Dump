class Solution {
public:
    bool isValid(int row, int col, int x, int y){
        if(x>=0 && x < row){
            if(y>=0 && y<col){
                return true;
            }
        }
        return  false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> num(row, vector<int>(col,0));
        
        int dx[8] = {0,0,1,-1,1,1,-1,-1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                for(int k = 0; k < 8; k++){
                    
                    if(board[i][j] == 1){
                        int x = i+dx[k];
                        int y = j+dy[k];
                    
                        if(isValid(row,col,x,y)){
                            num[x][y]++;
                        }
                    }
                    
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                if(board[i][j] == 1 && num[i][j] < 2) board[i][j] = 0;
                else if(board[i][j] == 1 && (num[i][j] == 2 || num[i][j] == 2)) board[i][j] = 1;
                else if(board[i][j] == 1 && num[i][j] > 3) board[i][j] = 0;
                else if(board[i][j] == 0 && num[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};

// https://leetcode.com/problems/game-of-life
