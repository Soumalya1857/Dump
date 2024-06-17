#include<bits/stdc++.h>
using namespace std;

static int dp[100][100];

int LCS(string x, string y, int m, int n) // m, n are lengths
{
    if(m==0 || n==0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    if(x[m-1] == y[n-1])
        return dp[m][n] = 1 + LCS(x,y,m-1,n-1);

    else 
        return dp[m][n] = max(LCS(x,y,m-1,n), LCS(x,y,m,n-1));
}


int LCStopDown(string x, string y, int m, int n)
{
    memset(dp, -1, sizeof(dp));

    int i,j;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(i==0 || j==0) dp[i][j] = 0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1] == y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[m][n];
}
int main()
{

    string a = "abcdefghijklmnop";
    string b = "axbycidopsidjfpaosidfpaduhf";

    memset(dp, -1, sizeof(dp));
    cout << LCS(a,b,a.length(),b.length()) << endl;
    return 0;
}

// ========================================================
class Solution{
    public:

        int solve(string &s1, string &s2, int i, int j){
            if(i<0 || j<0){
                return 0;
            }

            if(s1[i] == s2[j]){
                return 1+solve(s1, s2, i-1, j-1);
            }

            return max(solve(s1, s2, i-1, j), solve(s1, s2, i, j-1));
        }

        int longestCommonSubsequence(string s1, string s2){
            return solve(s1, s2, s1.length()-1, s2.length()-1);
        }
};