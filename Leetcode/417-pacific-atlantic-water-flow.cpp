class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    bool isValid(vector<vector<int>>&heights, int row, int col){
        if(row >=0 && row < heights.size()){
            if(col >= 0 && col < heights[0].size()){
                return true;
            }
        }

        return false;
    }

    void bfs(vector<vector<int>>&heights, vector<vector<bool>>&ocean, vector<pair<int,int>>& points){
        queue<pair<int,int>> q;
        for(auto pair : points){
            q.push(pair);
        }

        while(!q.empty()){
            pair<int,int> curr = q.front(); q.pop();
            ocean[curr.first][curr.second] = true;

            for(int i=0; i<4;i++){
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if(isValid(heights, x, y) && heights[x][y] >= heights[curr.first][curr.second] && ocean[x][y] == false){
                    q.push({x,y});
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        int row = heights.size(), col = heights[0].size();
        // ans.push_back(vector<int>{heights[0][col-1]});
        // ans.push_back(vector<int>{heights[row-1][0]});

        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        vector<pair<int,int>> points;

       // pacific
       for(int i=0; i<row; i++){
           if(!pacific[i][0]){
               points.push_back({i,0});
           }
       }

       for(int j=1; j<col; j++){
           if(!pacific[0][j]){
               points.push_back({0,j});
           }
       }

       bfs(heights, pacific, points);

       points.clear();

       // atlantic

       for(int i=0; i<row; i++){
           if(!atlantic[i][col-1]){
               points.push_back({i, col-1});
           }
       }

       for(int j=0; j<col; j++){
           if(!atlantic[row-1][j]){
              points.push_back({row-1, j});
           }
       }

       bfs(heights, atlantic, points);

       // match and answer
       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               if(pacific[i][j] && atlantic[i][j]){
                   ans.push_back(vector<int>{i,j});
               }
           }
       }
       return ans;
        
    }
};

//https://leetcode.com/problems/pacific-atlantic-water-flow/
// get where you can reach from atlantic and pacific separately
// take the intersection 

// dfs is better