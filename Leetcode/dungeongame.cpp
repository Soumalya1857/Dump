class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(),i,j,k;
        int col = dungeon[0].size();
        if(row == 0 || col == 0) return -1;
        
        int dp[row][col];
        // each cell contains min health require to enter cell[i][j] (before entering)
        dp[row-1][col-1] = dungeon[row-1][col-1];
        if(dungeon[row-1][col-1] > 0)  dp[row-1][col-1] = 1;
        else  dp[row-1][col-1] = 1 - dungeon[row-1][col-1];
        
        
         //lets solve the last row and column
        for(j=col-2; j>=0;j--) dp[row-1][j] = max(dp[row-1][j+1]-dungeon[row-1][j],1);
        for(i=row-2; i>=0;i--) dp[i][col-1] = max(dp[i+1][col-1]-dungeon[i][col-1],1);
        
        
        
        for(i=row-2;i>=0;i--)
        {
            for(j=col-2;j>=0;j--)
            {
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j] , 1);
            }
        }
        return dp[0][0];  
    }


    /**
     * 
     * https://leetcode.com/problems/dungeon-game
     * /