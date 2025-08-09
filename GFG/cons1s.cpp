
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define TEST ll test; cin >> test; while(test--)
using namespace std;

int main() {
	//code
	register ll i,j;
    TEST
    {
        ll n,ans=0;
        cin >> n;
        ll dp[n+1];
        //dp[n] = dp[n-1] + dp[n-2]
        dp[1]=2 ;dp[2]=3;
        //basically fibbonacci number
        for(i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= MOD;
        }
        cout << dp[n] << endl;
    }
	return 0;
}