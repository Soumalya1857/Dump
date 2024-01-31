class Solution {

private:
    bool isValid(int row, int col,int  xpos, int ypos){
        return xpos>=0 && xpos<row && ypos>=0 && ypos<col;
    }
public:

struct Node{
    int x,y,max;
    Node(int x, int y, int max) : x(x), y(y), max(max){}
};

struct myComp {
    constexpr bool operator()(
        Node & a,
        Node & b)
        const noexcept
    {
        return a.max > b.max;
    }
};


    int swimInWater(vector<vector<int>>& grid) {
        // path where the max height is the minimum
        // greedy minimum path

        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        // vector<vector<int>> dp(row, vector<int>(col, INT_MAX));

        int currRow = 0, currCol = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int maxVal = -1;

        // dp[0][0] = grid[0][0];
        priority_queue<Node, vector<Node>, myComp> pq; // curr, max => sorted on Node.max => ascending 0 8 9 12 17 18
        Node node(0,0,grid[0][0]);

        pq.push(node);

        while(!pq.empty()){
            Node curr = pq.top(); pq.pop();

            cout << curr.x << " " << curr.y << " " << curr.max << endl;
            visited[curr.x][curr.y] = true;
            maxVal = max(maxVal, curr.max);
            if(curr.x == row-1 && curr.y == col-1){
                return maxVal;
            }

            for(int i=0; i<4; i++){
                int xpos = curr.x + dx[i];
                int ypos = curr.y + dy[i];

                if(isValid(row, col, xpos, ypos) && !visited[xpos][ypos]){
                    pq.push(Node(xpos, ypos, max(grid[xpos][ypos],curr.max)));
                }
            }
        }

        return -1;

        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){

        //         for(int k=0; k<4; k++){
        //             int xpos = i + dx[k];
        //             int ypos = j + dy[k];

        //             if(isValid(row, col, xpos, ypos)){
        //                 if(xpos == 2 && ypos == 2){
        //                     cout << "i,j: " << i << " " << j << endl;
        //                     cout << "dp[xpos][ypos]: " << dp[xpos][ypos] << " dp[i][j]: " << dp[i][j] << endl;
        //                 }
        //                 dp[xpos][ypos] = min(dp[xpos][ypos], max(dp[i][j], grid[xpos][ypos]));
        //                 if(xpos == 2 && ypos == 2){
        //                     cout << "dp[xpos][ypos]: after" << dp[xpos][ypos] << endl;
        //                 }
        //             }
        //         }
        //     }
        // }

        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        //return dp[row-1][col-1];

        // stack<pair<int,int>> s;
        // s.push({0,0});

        // while(!s.empty()){
        //     currRow = s.top().first;
        //     currCol = s.top().second;

        //     //cout << "point: " << currRow << " " << currCol << "=> " << grid[currRow][currCol] << endl;
        //     s.pop();

        //     maxVal = max(maxVal, grid[currRow][currCol]);

        //     if(currRow == row-1 && currCol == col-1){
        //         continue;
        //     }

        //     visited[currRow][currCol] = true;

        //     int minVal = INT_MAX, x,y;
        //     for(int i=0; i<4; i++){
        //         int xpos = currRow + dx[i];
        //         int ypos = currCol + dy[i];

        //         if(isValid(row, col, xpos, ypos) && !visited[xpos][ypos]){
        //             if(grid[xpos][ypos] < minVal){
        //                 minVal = min(minVal, grid[xpos][ypos]);
        //                 x = xpos, y = ypos;
        //             }
        //         }
        //     }

        //     s.push({x,y});

        // }

        //return maxVal;


    }
};

// https://leetcode.com/problems/swim-in-rising-water/

// better solution in coming
// https://leetcode.com/problems/swim-in-rising-water/solutions/113758/c-two-solutions-binary-search-dfs-and-dijkstra-bfs-o-n-2logn-11ms

