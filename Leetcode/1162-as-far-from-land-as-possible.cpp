class Solution {
// TLE here-----going to every node and start BFS
// think of iterative BFS here
// kind of dp on bfs
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