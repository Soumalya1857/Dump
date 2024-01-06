class Solution {

private:

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    bool isValid(vector<vector<int>> &grid, int x, int y){
        return x>=0 && x<grid.size() && y>=0 && y<grid[0].size();
    }

    void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited){
        stack<pair<int,int>> s;
        s.push({x,y});

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            visited[curr.first][curr.second] = true;

            for(int i=0; i<4; i++){
                int xpos = curr.first + dx[i];
                int ypos = curr.second + dy[i];

                if(isValid(grid, xpos, ypos) && !visited[xpos][ypos] && grid[xpos][ypos] == 1){
                    s.push({xpos, ypos});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();


        vector<vector<bool>> visited(row, vector<bool> (col, false));


        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i==0 || i==row-1 || j==0 || j== col-1){
                    if(!visited[i][j] && grid[i][j] == 1){
                        dfs(grid, i, j, visited);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    ans++;
                }
            }
        }

        return ans;
    }
};

//https://leetcode.com/problems/number-of-enclaves/