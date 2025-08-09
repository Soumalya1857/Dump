
// worst AC ever written
class Solution {

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int n, int row, int col){
        if(row>=0 && row<n){
            if(col >=0 && col <n){
                return true;
            }
        }
        return false;
    }
    int abso(int n){
        return n < 0 ? -n : n;
    }

    int dist(int a, int b, int x, int y){
        return abso(a-x) + abso(b-y) -1;
    }

    void dfs(vector<vector<int>>&grid, int x, int y, int islandFound, vector<pair<int,int>> &island1, vector<pair<int,int>> &island2){

        stack<pair<int,int>> s;
        s.push({x,y});

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            grid[curr.first][curr.second] = 2;
            if(islandFound == 1) island1.push_back(curr);
            if(islandFound == 2) island2.push_back(curr);

            for(int i=0; i<4; i++){
                int xpos = curr.first + dx[i];
                int ypos = curr.second + dy[i];

                if(isValid(grid.size(), xpos, ypos) && grid[xpos][ypos] == 1){
                    s.push({xpos, ypos});
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int islandFound = 0;
        vector<pair<int,int>> island1, island2;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, ++islandFound, island1, island2);
                }

                if(islandFound == 2) break;
            }
        }


        // now we have all the points of all the islands
        int minFlips = INT_MAX;
        for(auto point1 : island1){
            for(auto point2 : island2){
                minFlips = min(minFlips, dist(point1.first, point1.second, point2.first, point2.second));
            }
        }

        return minFlips;

    }
};

// https://leetcode.com/problems/shortest-bridge/


//better solution 
// multisource bfs with multiple source and destination

class Solution {

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int n, int row, int col){
        if(row>=0 && row<n){
            if(col >=0 && col <n){
                return true;
            }
        }
        return false;
    }
    int abso(int n){
        return n < 0 ? -n : n;
    }

    int dist(int a, int b, int x, int y){
        return abso(a-x) + abso(b-y) -1;
    }

    void dfs(vector<vector<int>>&grid, int x, int y, int islandFound, vector<pair<int,int>> &island1){

        stack<pair<int,int>> s;
        s.push({x,y});

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            grid[curr.first][curr.second] = islandFound+1; // island1 => 2 island2 => 3

            island1.push_back(curr);

            for(int i=0; i<4; i++){
                int xpos = curr.first + dx[i];
                int ypos = curr.second + dy[i];

                if(isValid(grid.size(), xpos, ypos) && grid[xpos][ypos] == 1){
                    s.push({xpos, ypos});
                }
            }
        }
    }

    int bfs(vector<vector<int>> &grid,vector<pair<int,int>> &source){
        queue<pair<int,int>> q;
        for(auto point : source){
            q.push(point);
        }
        int dist = 0;

        while(!q.empty()){
            dist++;
            int size = q.size();
            while(size--){
                pair<int,int> point = q.front(); q.pop();

                if(grid[point.first][point.second] == 1) return dist-1;

                for(int i=0; i<4; i++){
                    int x = point.first + dx[i];
                    int y = point.second + dy[i];

                    if(isValid(grid.size(), x, y) && (grid[x][y] == 0 || grid[x][y] == 1)){
                        q.push({x,y});
                    }
                }
            }
        }

        return -1;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int islandFound = 0;
       vector<pair<int,int>> island1;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, ++islandFound, island1);
                }

                if(islandFound == 1) break;
            }
        }
        
        // multisource bfs
        int minFlips = bfs(grid, island1);

        return minFlips-1;
    }
};



class Solution {

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int n, int row, int col){
        if(row>=0 && row<n){
            if(col >=0 && col <n){
                return true;
            }
        }
        return false;
    }
    int abso(int n){
        return n < 0 ? -n : n;
    }

    int dist(int a, int b, int x, int y){
        return abso(a-x) + abso(b-y) -1;
    }

    void dfs(vector<vector<int>>&grid, int x, int y, int islandFound, vector<pair<int,int>> &island1){

        stack<pair<int,int>> s;
        s.push({x,y});

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            grid[curr.first][curr.second] = islandFound+1; // island1 => 2 island2 => 3

            island1.push_back(curr);

            for(int i=0; i<4; i++){
                int xpos = curr.first + dx[i];
                int ypos = curr.second + dy[i];

                if(isValid(grid.size(), xpos, ypos) && grid[xpos][ypos] == 1){
                    s.push({xpos, ypos});
                }
            }
        }
    }

    int bfs(vector<vector<int>> &grid,vector<pair<int,int>> &source){
        queue<pair<int,int>> q;
        for(auto point : source){
            q.push(point);
        }
        int dist = 0;

        while(!q.empty()){
            dist++;
            int size = q.size();
            while(size--){
                pair<int,int> point = q.front(); q.pop();

                if(grid[point.first][point.second] == 1) return dist-1;

                for(int i=0; i<4; i++){
                    int x = point.first + dx[i];
                    int y = point.second + dy[i];

                    if(isValid(grid.size(), x, y) && (grid[x][y] == 0 || grid[x][y] == 1)){
                        q.push({x,y});
                    }
                }
            }
        }

        return -1;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int islandFound = 0;
       vector<pair<int,int>> island1;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, ++islandFound, island1);
                }

                if(islandFound == 1) break;
            }
        }
        
        // multisource bfs
        int minFlips = bfs(grid, island1);

        return minFlips-1;
    }
};

// https://leetcode.com/problems/shortest-bridge/
// https://leetcode.com/problems/shortest-bridge/


// better solution
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int,int>> q;
        bool stop = false;
        for(int i=0;i<n && !stop;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid, q, i, j, n);
                    stop = true;
                    break;
                }
            }
        }

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        int count=0;
        while(!q.empty()){
            int m = q.size();
            count++;
            while(m--){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int X = x+dx[i];
                    int Y = y+dy[i];
                    if(X<0 || Y<0 || X>=n || Y>=n || grid[X][Y]==-1)
                        continue;
                    if(grid[X][Y]==1)
                        return count-1;
                    grid[X][Y] = -1;
                    q.push({X,Y});
                }
            }
        }
        return -1;
    }

    void dfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int i, int j, int n){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 || grid[i][j]==-1)
            return;
        q.push({i,j});
        grid[i][j] = -1;
        dfs(grid, q, i-1, j, n);
        dfs(grid, q, i+1, j, n);
        dfs(grid, q, i, j-1, n);
        dfs(grid, q, i, j+1, n);
    }
};



