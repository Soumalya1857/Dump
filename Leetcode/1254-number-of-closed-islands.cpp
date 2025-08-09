class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int row, int col, int xpos, int ypos){
        return xpos>=0 && xpos<row && ypos>=0 && ypos<col;
    }

    void dfs(vector<vector<int>> &grid, int x, int y){
        stack<pair<int,int>> s;
        s.push({x,y});

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            grid[curr.first][curr.second] = 1;

            for(int i=0; i<4; i++){
                int xpos = curr.first + dx[i];
                int ypos = curr.second + dy[i];

                if(isValid(grid.size(), grid[0].size(), xpos, ypos) && grid[xpos][ypos] == 0){
                    s.push({xpos, ypos});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        // mark all the non closed islands with 2
        // mark closed islands with 3


        int row = grid.size(), col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i==0 || i == row-1 || j==0 || j == col-1){
                    if(grid[i][j] == 0){
                        dfs(grid, i, j);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;

    }
};

// https://leetcode.com/problems/number-of-closed-islands/