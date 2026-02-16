class Solution {

    public int solve(int[][] grid, int row, int col, int currx, int curry, int[][] dp){
        if(currx >= row || curry >= col) return 0;
        
        if(grid[currx][curry] == 1) return 0; // gets priority, think of [0,0] [0,1]

        if(currx == row-1 && curry == col-1) {
            return 1;
        }

        if(dp[currx][curry] != 0) return dp[currx][curry];

        return dp[currx][curry] = solve(grid, row, col, currx+1, curry, dp) + solve(grid, row, col, currx, curry+1, dp);
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;

        int[][] dp = new int[row][col];

        return solve(obstacleGrid, row, col, 0, 0, dp);
    }
}

// https://leetcode.com/problems/unique-paths-ii/


// top down dp approach
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        //  0 0 0
        //  0 1 0
        //  0 0 0
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;

        int dp[][] = new int[n + 1][m + 1];
        dp[0][1] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 1 )
                    continue;
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[n][m];
    }
}

class Solution {
    static int MOD=1000000007;
    public static int solve(int i,int j,int [][]arr,int [][]dp){
        if(i<0 || j<0) return 0;
        if(arr[i][j]== 1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,arr,dp);
        int left=solve(i,j-1,arr,dp);
        dp[i][j]=(up+left);
        return dp[i][j];
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        int dp[][]=new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(n-1,m-1,obstacleGrid,dp);
    }
}
