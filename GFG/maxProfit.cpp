
/**
 * 
 * n stock market , a person buys a stock and sells it on some future date. Given the stock prices of N days in an form of an array A[ ] and a positive integer K, find out the maximum profit a person can make in atmost K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains a positve integer K, denoting the number of transactions.The second line of each test case contains a positve integer N, denoting the length of the array A[ ].The third line of each test case contains a N space separated positive integers, denoting the prices of each day in the array A[ ].

Output:
Print out the maximum profit earned by the person.No profit will be equivalent to 0.

Constraints:
1 <= T <= 100
0 <   K <= 10
2 <= N <=30
0 <= A[ ] <= 1000

Examples: 
Input:
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Output:
87
1040
0
 * 
*/

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

ll profit(int price[],int n,int k)
{
    int dp[k+1][n+1];//dp[i][j] denotes max profit using at most i transactions upto day j(including)
    for(int i=0;i<=n;i++) dp[i][0] = 0;// day 0 profit 0
    for(int i=0;i<=k;i++) dp[0][i] = 0; // transaction 0....profit 0

    for(int i=1;i<=k;i++)
    {
        for(int j= 1;j< n;j++)
        {
            int max_so_far = INT_MIN;
            for(int m=0; m < j;m++)
            {
                max_so_far = max(max_so_far, price[j] - price[m] + dp[i-1][m]);
                max_so_far = max(max_so_far,dp[i][j-1]);
            }
        }
    }
    // for(int i=0;i<=k;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
    return dp[k][n-1];

}

int main() 
{ 
    love you codechef
    register ll i,j;
    TEST
    {
        ll k,n;
        cin >> k >> n;
        int a[n];
        for(i=0;i<n;i++) cin >> a[i];
        ll ans = profit(a,n,k);
        cout << "ans: " << ans << endl;


    }
    return 0;
}