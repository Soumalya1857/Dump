// nice question 
// its about your 3d DP


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
     // we will do it generally
        // such that we have k transjactions to make
        
        int k = 2;
        int n = prices.size();
        int dp[k+1][n];
        // dp[i][j] = max profit get on jth day using i transactions
        
        for(int i=0;i<=k;i++)
            for(int j=0;j<n;j++)
                if(i ==0 || j == 0) dp[i][j] = 0;
        
        for(int i = 1;i<=k;i++)
        {
            for(int j = 1; j<n; j++)
            {
                int maxVal = -500;
                for(int m=0; m<j; m++)
                   maxVal = max(maxVal, prices[j]-prices[m]+dp[i-1][m]);
                
                dp[i][j] = max(dp[i][j-1], maxVal);
                                /*no transaction*/    /*sell on jth day...buy on mth day...profit = profit on mth day with i-1 trans + current profit*/
            }
        }
        
        return dp[k][n-1];
    }
};

// O(k*day*day)



########################################################3
//This can be made faster also  O(k*day)
#######################################################3



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
     // we will do it generally
        // such that we have k transjactions to make
        
       // int k = 2;
        int n = prices.size();
        if(n==0) return 0;
        //int dp[k+1][n];
        vector<vector<int>>dp(k+1, vector<int>(n));
        // dp[i][j] = max profit get on jth day using i transactions
        
        for(int i=0;i<=k;i++)
            for(int j=0;j<n;j++)
                if(i ==0 || j == 0) dp[i][j] = 0;
        
        for(int i = 1;i<=k;i++)
        {
            int maxDiff = -prices[0];
            for(int j = 1; j<n; j++)
            {
                dp[i][j] = max(dp[i][j-1], maxDiff+prices[j]);
                maxDiff = max(maxDiff, dp[i-1][j]-prices[j]);
            }
        }
        
        return dp[k][n-1];
    }
};

/**
     * This is faster method which does optimization on slower method
     * Time complexity here is O(K * number of days)
     *
     * Formula is
     * T[i][j] = max(T[i][j-1], prices[j] + maxDiff)
     * maxDiff = max(maxDiff, T[i-1][j] - prices[j])
     */


