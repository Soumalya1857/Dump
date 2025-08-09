#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define MOD 1000000007
#define MOD1 998244353

#define love ios_base::sync_with_stdio(false);
#define you cin.tie(NULL);
#define codechef cout.tie(NULL);
#define TEST ll test; cin >> test; while(test--)

using namespace std;

int main() 
{ 
    love you codechef
    register ll i,j,x;
    TEST
    {
        int n,k;
        cin >> n >> k;
        int dp[n+1][k+1];//dp[i][j] stores min no of trials in worst case in i eggs and k floors
        int res;
        for(i=1;i<=n;i++) dp[i][1] = 1,dp[i][0] = 0;
        for(i=1;i<=k;i++) dp[1][i] = i;

        for(i=2;i<=n;i++)
        {
            for(j=2;j<=k;j++)
            {
                dp[i][j] = INT_MAX;
                for(x = 1;x<=j;x++)
                {
                    res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                                // egg breaks        //egg doesn't break
                    dp[i][j] = min(dp[i][j],res);
                }
            }
        }
        cout << dp[n][k] << "\n";

    }
    return 0;
}
/***
 * 
 * 
 * https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
 * 
 * 
 * 
 * When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn’t break.

If the egg breaks after dropping from ‘xth’ floor, then we only need to check for floors lower than ‘x’ with remaining eggs as some floor should exist lower than ‘x’ in which egg would not break; so the problem reduces to x-1 floors and n-1 eggs.
If the egg doesn’t break after dropping from the ‘xth’ floor, then we only need to check for floors higher than ‘x’; so the problem reduces to ‘k-x’ floors and n eggs.
 * ***/