class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void printt(vector<vector<char>> &grid){
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                cout << grid[i][j] << " ";
            }
            
            cout << endl;
        }

        cout << "+++++++++++++++++++++++++++++++++++\n";
    }

    bool isValid(int row, int col, int i, int j){
        if(i>=0 && i<row){
            if(j>=0 && j<col){
                return true;
            }
        }

        return false;
    }

    void dfs(vector<vector<char>>&grid, int row, int col){
        stack<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty()){
            pair<int,int> curr = q.top(); q.pop();

            grid[curr.first][curr.second] = '2';

            for(int i=0; i<4; i++){
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if(isValid(grid.size(), grid[0].size(), x, y) && grid[x][y] == '1'){
                    q.push({x,y});
                }
            }

        }

        // cout << "row: " << row << " col: " << col << endl;
        // printt(grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();


        int ans = 0;
        for(int i = 0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/number-of-islands/description/