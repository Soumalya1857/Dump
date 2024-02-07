class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0) return 0;

        if(dp[n] != INT_MAX) return dp[n];

        int minVal = INT_MAX;

        for(int i=1;;i++){
            if(n - i*i >= 0){
                minVal = min(minVal, solve(n - i*i, dp));
            } else break;
        }
        //cout << "n: " << n << " ";
        return dp[n] = 1 + minVal;
    }

    int numSquares(int n) {
        vector<int> dp(n+2, INT_MAX);
        dp[1] = 1;
        dp[0] = 0;
        solve(n, dp);

        return dp[n];
    }
};

// https://leetcode.com/problems/perfect-squares/