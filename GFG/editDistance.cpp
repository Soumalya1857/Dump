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
        ll t;
	cin >> t;
	while(t--)
	{
	    ll m,n;
	    cin >> m >> n;
	    string a,b;
	    cin >> a >> b;

        ll dp[p+1][q+1];// dp[i][j] for cost for change a[i] and b[j] equal
        for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],min(  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1])); // Replace
        }
        cout << dp[m][n] << "\n";
    }


	    
    }
    return 0;
}
/******
 * 
 * https://practice.geeksforgeeks.org/problems/edit-distance/0
 * ******/