class Solution {
// TLE here-----going to every node and start BFS
// think of iterative BFS here
// kind of dp on bfs

// instead of starting from 0's,
// start from 1's and go untill you visit all the nodes...return the number of steps you have taken
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int N, int x, int y){
        return x>=0 && x<N && y>=0 && y<N;
    }

    int bfs(vector<vector<int>> &grid, int row, int col){
        int distance = 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));

        q.push({row,col});

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> curr = q.front(); q.pop();

                if(grid[curr.first][curr.second] == 1){
                    return distance;
                }
                visited[curr.first][curr.second] = true;

                for(int i=0; i<4; i++){
                    int xpos = curr.first + dx[i];
                    int ypos = curr.second + dy[i];

                    if(isValid(grid.size(), xpos, ypos) && !visited[xpos][ypos]){
                        q.push({xpos, ypos});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int maxDist = -1;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == 0){
                    maxDist = max(maxDist, bfs(grid, i, j));
                }
            }
        }

        return maxDist;
    }
};

//https://leetcode.com/problems/as-far-from-land-as-possible/

// think of iterative bfs

// better solution but not passed

class Solution {

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int N, int x, int y){
        return x>=0 && x<N && y>=0 && y<N;
    }

    void bfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dist){

        if(grid[row][col] == 1){
            dist[row][col] = 0;
            return;
        } else if(grid[row][col] == 2){
            return;
        }

        // visit
        grid[row][col] = 2;

        queue<pair<int,int>> q;
        for(int i=0; i<4; i++){
            int xpos = row + dx[i];
            int ypos = col + dy[i];

            if(isValid(grid.size(), xpos, ypos) && grid[xpos][ypos] != 2){
                q.push({xpos, ypos});
            }
        }

        while(!q.empty()){
            pair<int,int> curr = q.front(); q.pop();

            bfs(grid, curr.first, curr.second, dist);
            dist[row][col] = min(dist[row][col], 1+dist[curr.first][curr.second]);
        }
    }


public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int maxDist = -1;

        vector<vector<int>> dist(N, vector<int>(N, 10000));

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == 0){
                    bfs(grid, i, j, dist);
                }
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // cout << dist[i][j] << " ";
                if(dist[i][j] != 10000)
                    maxDist = max(maxDist, dist[i][j]);
            }
            //cout << endl;
        }

        return maxDist;
    }
};

// need to see the things

// start from the land and flood the water with distance and bfs
// still ERROR
class Solution {

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int N, int row, int col){
        return row>=0 && row<N && col>=0 && col<N;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        vector<vector<int>> dist(N, vector<int>(N,0));

        queue<pair<int,int>> q;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }

        int distance = 0;
        while(!q.empty()){

            int size = q.size();
            while(size--){
                pair<int,int> curr = q.front(); q.pop();

                visited[curr.first][curr.second] = true;
                if(grid[curr.first][curr.second] == 0)
                    dist[curr.first][curr.second] = distance;

                for(int i=0; i<4; i++){
                    int xpos = curr.first + dx[i];
                    int ypos = curr.second + dy[i];

                    if(isValid(grid.size(), xpos, ypos) && !visited[xpos][ypos]){
                        q.push({xpos, ypos});
                    }
                }
            }

            distance++;

        }

        int maxDist = -1;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == 0){
                    maxDist = max(maxDist, dist[i][j]);
                }
            }
        }

        return maxDist;
    }
};
// ================================================================================
// accepted soluton
class Solution {

private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int N, int row, int col){
        return row>=0 && row<N && col>=0 && col<N;
    }
public:
    int maxDistance(vector<vector<int>>& g) {
        int steps = 0;
        queue<pair<int, int>> q, q1;
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
            if (g[i][j] == 1)
                q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
        while (!q.empty()) {
            ++steps;
            while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
                g[i][j] = steps;
                q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
            }
            }
            swap(q1, q);
        }
        return steps == 1 ? -1 : steps - 1;
    }
    // {
    //     int N = grid.size();
    //     vector<vector<bool>> visited(N, vector<bool>(N, false));
    //     vector<vector<int>> dist(N, vector<int>(N,0));

    //     queue<pair<int,int>> q;

    //     for(int i=0; i<N; i++){
    //         for(int j=0; j<N; j++){
    //             if(grid[i][j] == 1) {
    //                 for(int idx=0; idx<4; idx++){
    //                     int x = i+dx[idx];
    //                     int y = j+dy[idx];

    //                     if(isValid(N,x,y) && grid[x][y] == 0){
    //                         q.push({x,y});
    //                     }
    //                 }
    //             }

    //         }
    //     }

    //     int distance = 0;
    //     while(!q.empty()){
    //         distance++;
    //         int size = q.size();
    //         while(size--){
    //             pair<int,int> curr = q.front(); q.pop();

    //             visited[curr.first][curr.second] = true;
    //             if(grid[curr.first][curr.second] == 0)
    //                 dist[curr.first][curr.second] = distance;

    //             for(int i=0; i<4; i++){
    //                 int xpos = curr.first + dx[i];
    //                 int ypos = curr.second + dy[i];

    //                 if(isValid(grid.size(), xpos, ypos) && !visited[xpos][ypos] && grid[xpos][ypos] == 0){
    //                     q.push({xpos, ypos});
    //                 }
    //             }
    //         }

    //         //distance++;

    //     }

    //     int maxDist = -1;
    //     for(int i=0; i<N; i++){
    //         for(int j=0; j<N; j++){
    //             cout << dist[i][j];
    //             maxDist = max(maxDist, dist[i][j]);
    //             if(dist[i][j] == 4) cout << "#";
    //             cout << " ";

    //         }
    //         cout << endl;
    //     }

    //     return maxDist;
    // }
};