// dp solution 
class Solution {

private:
    int MOD = 1e9+7;

    int dx[8] = {2,  2, -2, -2, 1, -1,  1, -1};
    int dy[8] = {1, -1,  1, -1, 2,  2, -2, -2};

    int gridRow = 4, gridCol = 3;

    bool isValid(int x, int y){
        if((x>=0 && x<gridRow && y>=0 && y<gridCol)){
            if((x == gridRow-1 && y ==0 ) || (x == gridRow-1 && y==gridCol-1)) return false;
            else return true;
        }
        return false;
    }


    int solve(int x, int y, int n, vector<vector<vector<int>>> &dp){
        if(n == 1){
            return 1;
        }

        if(dp[x][y][n] != -1) return dp[x][y][n];

        int ans = 0;

        for(int i=0; i<8; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(isValid(newX, newY)){
                ans = (ans + solve(newX, newY, n-1, dp)) % MOD;
                ans %= MOD;
            }
        }

        return dp[x][y][n] = ans % MOD;
    }
public:

    int knightDialer(int n) {

        int ans = 0;
        //vector<int> dp(n+1, -1);

        // 3D dp
        vector<vector<vector<int>>> dp(gridRow, vector<vector<int>>(gridCol, vector<int>(n+1,-1)));

        for(int i=0; i<gridRow; i++){
            for(int j=0; j<gridCol; j++){
                if(isValid(i,j)){
                    ans += (solve(i,j,n, dp) % MOD);
                    ans %= MOD;
                }
            }
        }

        return ans;
    }


};


// https://leetcode.com/problems/knight-dialer/



// crazy MCM technique

#pragma GCC optimize("O3")
const int mod = 1e9 + 7;
vector<vector<int>> M = {
    {0, 2, 2, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 2},
    {0, 0, 1, 0}
};
vector<vector<int>> I = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};
vector<vector<int>> operator*(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    int k1 = A[0].size();
    int k2 = B.size();
    int m = B[0].size();
    if (k1 != k2) return {};
    vector<vector<int>> C(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            #pragma unroll
            for (int k = 0; k < k1; k++)
                C[i][j] = (C[i][j] + (long long)A[i][k] * B[k][j] % mod) % mod;
        }
    }
    return C;
}
vector<vector<int>> pow(vector<vector<int>> M, int n) {
    if (n == 0) return I;
    vector<vector<int>> A = (n & 1) ? M : I;
    return pow((M * M), n / 2) * A;
}
class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        n--;
        vector<vector<int>> A = vector<vector<int>>({{1, 1, 1, 1}}) *
        pow(M, n) * vector<vector<int>>({{4}, {2}, {2}, {1}});
        
        return A[0][0];
    }
};