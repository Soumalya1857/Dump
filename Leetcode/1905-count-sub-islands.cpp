class Solution {
// idea here is to find a cross-section b/w grid1 and grid2
// traverse on the cross-section to see if any of the "2" is surrounded by '1' or not
// this means there is a part of grid2 which is not there is grid1
// don't stop the dfs as we still need to visit all the element
// bfs and dfs works only on unweighted or identical edges

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int row, int col, int x, int y){
        return x>=0 && x<row && y>=0 && y<col;
    }

    int bfs(vector<vector<int>> &grid, int x, int y){

        stack<pair<int,int>> q;
        q.push({x,y});
        int row = grid.size(), col=grid[0].size();

        bool isSubIsland = true;

        while(!q.empty()){
            pair<int,int> curr = q.top(); q.pop();

            grid[curr.first][curr.second] = -2;

            for(int i=0; i<4; i++){
                int xpos = curr.first + dx[i];
                int ypos = curr.second + dy[i];

                if(isValid(row, col, xpos, ypos)){
                    if(grid[xpos][ypos] == 2){
                        q.push({xpos, ypos});
                    } else if(grid[xpos][ypos] == 1){
                        isSubIsland = false;
                    }
                }

            }
        }

        return isSubIsland ? 1 : 0;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // modifying grid2

        int row = grid2.size(), col=grid2[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid2[i][j] && grid1[i][j]){
                    grid2[i][j] += grid1[i][j];
                }
            }
        }

        int island=0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid2[i][j] == 2){
                    island += bfs(grid2, i, j);
                }
            }
        }

        return island;
    }
};

// https://leetcode.com/problems/count-sub-islands/