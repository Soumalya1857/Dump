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

void backtrace(string x, string y, int m, int n)
{
    // now our dp is ready
    int i=m, j=n;
    string res = "";
    while(i>0 && j>0) // while any of the string gets empty
    {
        if(x[i-1] == y[j-1]) {
            res += x[i-1];
            i--;
            j--;
        }
        else 
        {
            if(dp[i-1][j] > dp[i][j-1])
            {
                i = i-1;
            }
            else j = j-1;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main()
{

    string a = "abcdefghijklmnop";
    string b = "axbycidopsidjfpaosidfpaduhf";

    memset(dp, -1, sizeof(dp));
    cout << LCS(a,b,a.length(),b.length()) << endl;
    backtrace(a,b,a.length(),b.length());
    return 0;
}