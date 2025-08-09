//https://leetcode.com/problems/minimum-falling-path-sum/

class Node{

    public:

    int row;
    int col;
    int sum;

    Node(int row, int col, int sum){

        this->row = row;
        this->col = col;
        this->sum = sum;
    }

    int getRow(){return row;}
    int getCol(){return col;}
    int getSum(){return sum;}
};

class Solution {

    private:
       int dy[3] = {-1,0,1};

       int solve(vector<vector<int>>& matrix, int x, int y, vector<vector<int>> &dp){

            if(y<0 || y >= matrix[0].size()){
                return 1e8;
            }



            if(x==matrix.size()){
                return 0;
            }
            if(dp[x][y] != -1e8){
                return dp[x][y];
            }

            return dp[x][y] = matrix[x][y] + min(solve(matrix, x+1, y, dp), min(solve(matrix, x+1, y-1, dp), solve(matrix,x+1,y+1, dp)));
       }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int mini = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1e8));
        for(int j=0; j<matrix[0].size(); j++){
            mini = min(mini, solve(matrix, 0, j, dp));
        }

        return mini;
    }
};

// https://leetcode.com/problems/minimum-falling-path-sum/