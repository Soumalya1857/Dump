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
    register ll i,j;
    TEST
    {
        int n,m;
        cin >> n >> m;
        bool a[n][m];
        int dp[n][m];//dp[i][j] contains the size of the square possible at position i,j being the right bottom most position
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            dp[i][0] = (int)a[i][0];
        }
        for(j=0;j<m;j++)
        {
            dp[0][j] = (int)a[0][j];
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                 dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
        ll maxi = -10;
        ll maxX = -1;
        ll maxY = -1;
        cout << "\n\n\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout << dp[i][j] << " ";
                if(dp[i][j] >= maxi)
                {
                    maxi = dp[i][j];
                    maxX = i;
                    maxY = j;
                }
            }
            cout << "\n";
        }
        cout << "\nsize: " << maxi << "\n" << "  pos: " << maxX <<"  " << maxY << "\n";
    }
    return 0;
}