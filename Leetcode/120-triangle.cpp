class Solution {
public:

    bool isValid(int row, int i, int j){
        if(i >=0 && i<row){
            if(j>=0 && j<i+1){
                return true;
            }
        }
        return false;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1, vector<int>(triangle.size()+1,INT_MAX));
        return solve(triangle, 0, 0, dp);
    }

    int solve(vector<vector<int>> &triangle, int row, int col, vector<vector<int>>&dp) {
        if(!isValid(triangle.size(), row, col))
            return 0;

        if(dp[row][col] != INT_MAX) 
            return dp[row][col];

        if(dp[row+1][col] == INT_MAX)
            dp[row+1][col] = solve(triangle, row+1, col, dp);

        if(dp[row+1][col+1] == INT_MAX)
            dp[row+1][col+1] = solve(triangle, row+1, col+1, dp);

        return dp[row][col] = triangle[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
    }
};

// https://leetcode.com/problems/triangle/submissions/1110479214/