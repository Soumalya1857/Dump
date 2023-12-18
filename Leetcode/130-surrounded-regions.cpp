class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(vector<vector<char>>&board, int row, int col){
        if(row >= 0 && row <board.size()){
            if(col >= 0 && col < board[0].size()){
                return true;
            }
        }

        return false;
    }

    void dfs(vector<vector<char>>&board, vector<pair<int,int>> &points){
        stack<pair<int,int>> s;
        for(pair<int,int> pair : points){
            s.push(pair);
        }

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            board[curr.first][curr.second] = '1';

            for(int i=0; i<4; i++){
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if(isValid(board, x, y) && board[x][y] == 'O'){
                    s.push({x,y});
                }
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();

        vector<pair<int,int>> points;
        for(int i=0; i<row; i++){
            if(board[i][0] == 'O') points.push_back({i,0});
            if(board[i][col-1] == 'O') points.push_back({i,col-1});
        }

        for(int j=1; j<col-1; j++){
            if(board[0][j] == 'O') points.push_back({0,j});
            if(board[row-1][j] == 'O') points.push_back({row-1,j});
        }

        // for(auto i : points){
        //     cout << i.first << " " << i.second << "\n";
        // }

        dfs(board, points);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }

        // return board;
    }
};

// https://leetcode.com/problems/surrounded-regions/submissions/1117274086/