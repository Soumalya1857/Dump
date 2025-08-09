class Solution {
public:
    int solve(vector<int> &prices, bool buy, int transactions, int index, int &k, vector<vector<vector<int>>> &dp ){
        if(index >= prices.size() || transactions >= k){
            return 0;
        } 

        if(dp[index][buy][transactions] != -1) return dp[index][buy][transactions];   

        if(buy){
            return dp[index][buy][transactions] = max( solve(prices, buy, transactions, index+1, k,dp), -prices[index]+solve(prices, !buy, transactions, index+1, k, dp));
        }else{
            return dp[index][buy][transactions] = max( solve(prices, buy, transactions, index+1, k, dp), prices[index] + solve(prices, !buy, transactions+1, index+1, k, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k, -1)));

        return solve(prices, true, 0, 0, k, dp);
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// iterative version
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // If there are no prices or k is 0, return 0 profit
        if (n == 0 || k == 0) return 0;
        
        // If k is larger than half of the days, we can perform unlimited transactions
        if (k >= n / 2) {
            int totalProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    totalProfit += prices[i] - prices[i - 1];
                }
            }
            return totalProfit;
        }

        // Dynamic Programming table
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        // Fill the DP table
        for (int i = 1; i <= k; i++) {
            int max_prev = -prices[0]; // This stores the maximum value of dp[i-1][m] - prices[m]
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + max_prev);
                max_prev = max(max_prev, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][n - 1]; // Maximum profit with k transactions on the last day
    }
};