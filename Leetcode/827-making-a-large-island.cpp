// Brute approach TLE
class Solution {
private:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0,  0, 1, -1};

    bool isValid(int n, int row, int col){
        return row>=0 && row<n && col>=0 && col<n;
    }

    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited){
        int n = grid.size();
        queue<pair<int,int>> q;

        int size = 0;

        q.push({row,col});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(!visited[x][y]){
                size++;
                visited[x][y] = true;
            }
            
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(isValid(n, newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY]){
                    q.push({newX, newY});
                }
            }

        }

        return size;


    }

    int findLargest(vector<vector<int>> &grid){
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        

        int islandSize = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    islandSize = max(islandSize, solve(grid, i, j, visited));
                }
            }
        }

        return islandSize;

    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        // BRUTE approach
        // turn each 0 to 1 and check size of largest Island

        int n = grid.size();
        bool flag = false;
        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    flag = true;
                    grid[i][j] = 1;
                    maxi = max(maxi, findLargest(grid));
                    grid[i][j] = 0;
                }
            }
        }

        if(!flag) return n*n;
        return maxi;
    }
};

// https://leetcode.com/problems/making-a-large-island/description/




