class Solution {
public:
    int uniquePaths(int m, int n) {
        // it has to take 3 down and 7 right path
        // m+n C m * n C n => m+n C m
        // basically its a code to print ncr
        
        long long p = 1, k = 1,r=min(m-1,n-1), t=m+n-2; // print value of tCr and -2 coz n-1 and m-1 moves are allowed
        if(r==0) return 1;
        while(r){
            p *= t;
            k *= r;
            
            long long gcd = __gcd(p,k);
            p /= gcd;
            k /= gcd;
            
            t--;
            r--;
        }
        
        return p;
    }
};

// prob: https://leetcode.com/problems/unique-paths/
// approach: https://www.geeksforgeeks.org/program-to-calculate-the-value-of-ncr-efficiently/

// solution: DP

class Solution {
public:

    int solve(int m, int n, int row, int col, vector<vector<int>> &dp){
        if(m == row-1 && n == col-1){
            return 1;
        }

        if(m<0 || m >= row || n<0 || n>= col) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int count = 0;
        count += solve(m+1,n,row,col, dp);
        count += solve(m,n+1,row,col, dp);

        return dp[m][n] = count;

        /* another clean solution

            return dp[m][n] = solve(m+1,n,row,col)+solve(m,n+1,row,col);
        */
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0,0,m,n, dp);

    }
};