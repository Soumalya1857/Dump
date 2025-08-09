// no of ways to get a value

// we need to reach value n and we have suppy of m diff denominations
// lets say denomination arr is d[m];


// dp[i][j] = getting value i using 0.....j-1th deniminations
int getNumber(int n, int d[], int m)
{
    int dp[n+1][m];
    for(int i=0;i<m;i++) dp[0][i] = 1;// 

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] = dp[i][j-1]/*not considering jth denomination*/
                        + dp[i-d[j]][j]; /*adding jth denomination at last..so getting i-d[j] using 0...j-1 th denomination*/
        /*add an additional checking if j-1 and i-d[j] is valid or not*/
        /*if not valid give 0 instead of them*/
        }
    }
}