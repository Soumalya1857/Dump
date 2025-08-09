class Solution {
private: 
    int solve(int n, int partition, vector<int> &dp){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int maxi = 0;
        int limit = partition == 0 ? n-1 : n;
        for(int i=1; i<=limit;i++){
            //if(i == n && partition == 0) return 0;
            maxi = max(maxi, i * solve(n-i, partition+1, dp));
        }

        return dp[n] = maxi;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,0, dp);
    }
};

// https://leetcode.com/problems/integer-break/