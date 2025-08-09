//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60

class Solution{

    private:
        int dx[4] = {1,0, 0, -1};
        int dy[4] = {0,-1, 1, 0};
        char dir[4] = {'D', 'L', 'R', 'U'};

        bool isValid(int n, int x, int y){
            return x>=0 && x<n && y>=0 && y<n;
        }

        void solve(vector<vector<int>> &m, int n, int x, int y, string path, vector<vector<bool>> &visited, vector<string> &ans){
            if(x == n-1 && y == n-1){
                ans.push_back(path);
                return;
            }

            visited[x][y] = true;

            for(int i=0; i<4; i++){
                int xNew = x + dx[i];
                int yNew = y + dy[i];

                if(isValid(n, xNew, yNew) && m[xNew][yNew] == 1 && !visited[xNew][yNew]){
                    path += dir[i];
                    visited[xNew][yNew] = true;
                    solve(m, n, xNew, yNew, path, visited, ans);

                    // backtrack
                    path = path.substr(0, path.length()-1);
                    visited[xNew][yNew] = false;
                }
            }
        }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here

        vector<string> ans;
        if(n == 0 || m[0][0] == 0) return ans;

        vector<vector<bool>> visited(n, vector<bool>(n,false));

        solve(m,n,0,0,"",visited, ans);

        return ans;

    }
};