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
        ll n,m;
        cin >> n >> m;
        string a,b;
        cin >> a >> b;
        ll dp[n+1][m+1];//dp[i][j] contains value of lcs upto a[0..i-1] & b[0...j-1]
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0 || j==0) dp[i][j] = 0;
                else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else
                {
                    dp[i][j] = 0;
                }
                
            }
        }
       ll maxi = INT_MIN;
       for(i=0;i<=n;i++)
       {
           for(j=0;j<=m;j++)
           {
               if(dp[i][j] > maxi) maxi = dp[i][j];
           }
       }
       cout << maxi << endl;
    }
    return 0;
}
/*******
 * https://practice.geeksforgeeks.org/problems/longest-common-substring/0
 * *****/