class Solution {
public:
    int solve(vector<int> &prices, bool buy, int transactions, int index, vector<vector<vector<int>>> &dp ){
        if(index >= prices.size() || transactions >= 2){
            return 0;
        } 

        if(dp[index][buy][transactions] != -1) return dp[index][buy][transactions];   

        if(buy){
            return dp[index][buy][transactions] = max( solve(prices, buy, transactions, index+1, dp), -prices[index]+solve(prices, !buy, transactions, index+1, dp));
        }else{
            return dp[index][buy][transactions] = max( solve(prices, buy, transactions, index+1, dp), prices[index] + solve(prices, !buy, transactions+1, index+1, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(prices, true, 0, 0, dp);
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// one optimization is use size*4 dp instead of size * 2 * 2

// general solution: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/



// o(N) solution
public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
}