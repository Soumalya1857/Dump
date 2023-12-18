
// TLEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
class Solution {

private:
    int dx[8] = {0,0,1,1,1,-1,-1,-1};
    int dy[8] = {1,-1,0,-1,1,0,-1,1};
    bool isValid(int n, int x, int y){
        if(x>=0 && x<n){
            if(y>=0 && y<n){
                return true;
            }
        }

        return false;
    }
    int bfs(vector<vector<int>> &grid, int x, int y){
        int n = grid.size();

        queue<pair<int,int>>q;
        q.push({x,y});
        int length = 0;

        while(!q.empty()){
            int size = q.size();
            length++;
            while(size--){
                pair<int,int> curr = q.front(); q.pop();

                if(curr.first == n-1 && curr.second == n-1){
                    return length;
                }

                grid[curr.first][curr.second] = -1;

                for(int i=0; i<8; i++){
                    int X = curr.first + dx[i];
                    int Y = curr.second + dy[i];

                    if(isValid(grid.size(), X, Y) && grid[X][Y] == 0){
                        q.push({X,Y});
                    }
                }
            }
        }

        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 0) return -1;

        if(grid.size() > 0){
            if(grid[0][0] != 0) return -1;
            if(grid[grid.size()-1][grid.size()-1] != 0) return -1;
        }

        return bfs(grid, 0, 0);
    }
};

// https://leetcode.com/problems/shortest-path-in-binary-matrix/






// think of optimization