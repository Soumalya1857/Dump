#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7

int main()
{
    
    ll test;
    cin >> test;
    while(test--){

        ll n;
        cin >> n;
        ll a[n];
        ll dp[n+1];
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
            dp[i+1] = LONG_LONG_MAX;
        }      

        dp[1] = 0;
        for(ll i=1;i<n;i++)
        {
            for(ll j=1;j<=a[i-1];j++)
            {
                if(i+j <= n)
                {
                    if(dp[i+j]>1+dp[i]) dp[i+j] = 1+dp[i];
                }
            }
        }

        if(dp[n] == LONG_LONG_MAX) cout << "-1" << endl;
        else cout << dp[n]-1 << endl;

    }

    return 0;
}


// https://leetcode.com/problems/burst-balloons/discuss/531519/matrix-chain-multiplication