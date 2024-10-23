class Solution {
public:
    int solve(vector<int> &prices, bool buy, int index, int &fee, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy){
            return dp[index][buy] =  max(solve(prices, buy, index+1, fee, dp), -prices[index]+solve(prices, !buy, index+1, fee, dp));
        }else{
            return dp[index][buy] = max(solve(prices, buy, index+1, fee, dp), -fee + prices[index]+solve(prices, !buy, index+1, fee, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return solve(prices, true, 0, fee, dp);
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/