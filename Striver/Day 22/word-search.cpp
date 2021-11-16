class Solution {
public:
    
    bool isValid(int row, int col, int i, int j)
    {
        if(i>=0 && i<row)
            if(j>=0 && j<col)
                   return true;
                        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        bool answer = false;
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j] == word[0])
                {
                    answer = dfs(board, i,j, 0, word);
                    if(answer) return answer;
                }
                   
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string word)
    {
        if(index == word.length()) return true;
        
        int row = board.size();
        int col = board[0].size();
        
        bool ans = false;
        
        if(isValid(row,col,i,j) && word[index] == board[i][j])
        {
            char temp = board[i][j];
            board[i][j] = '#';
            
            ans = dfs(board, i+1, j, index+1, word) 
                        || dfs(board, i,j+1, index+1, word)
                        || dfs(board, i-1, j, index+1, word)
                        || dfs(board, i,j-1, index+1, word);
            
            board[i][j] = temp;
        }
        
        return ans;
    }
};

// prb: https://leetcode.com/problems/word-search/submissions/