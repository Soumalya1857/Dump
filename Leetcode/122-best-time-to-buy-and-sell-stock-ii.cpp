class Solution {
public:

    int solve(vector<int> &prices, bool buy, int index, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy){
            return dp[index][buy] = max(solve(prices, buy, index+1, dp) , -prices[index] + solve(prices, !buy, index+1,dp));
        } else{
            return dp[index][buy] = max(solve(prices, buy, index+1, dp), prices[index] + solve(prices, !buy, index+1, dp));
        }
    }
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return solve(prices, true, 0, dp);
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/208241/explanation-for-the-dummy-like-me/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/39420/three-lines-in-c-with-explanation/ <= o(N) solution


