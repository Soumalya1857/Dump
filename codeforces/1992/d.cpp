#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define MOD 1000000007

#define love ios_base::sync_with_stdio(false);
#define you cin.tie(NULL);
#define codechef cout.tie(NULL);
#define TEST ll test; cin >> test; while(test--)

using namespace std;



bool solve(char a[], int index, int n, int m, int k, vector<vector<int>> &dp){
    if(k < 0){
        return false;
    }

    if(index >= n){
        return true;
    }

    if(a[index] == 'C'){ // got a croc bro
        return false;
    }

    if(dp[index][k] != -1){
        return dp[index][k];
    }

    // if he is on L or index == 0

    if(a[index] == 'L'){ // he can jump to m dist
        for(ll i=1; i<=m; i++){
            if(solve(a, index+i, n, m, k, dp) == true){
                return  dp[index][k] = true;
            }
        }
    }

    if(a[index] == 'W'){
        return dp[index][k] = solve(a, index+1, n,m, k-1, dp);
    }

    return dp[index][k] = false;

}

int main() {

        love you codechef
    TEST
    {
        ll n, m, k; // m is jump, k is total swimming
        cin >> n >> m >> k;

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

        char a[n];
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }


       bool ans = false;

       for(int i=0; i<m; i++){
            if(solve(a, i, n, m, k, dp) == true){
                ans = true;
                break;
            }
       }

       if(ans) cout << "YES\n";
       else cout << "NO\n";
    }
	return 0;
}

/*
ynamic programming solution: dpi
 −
 the minimum number of meters that need to be swum to reach the i
-th cell. The base case of the dynamic programming is dp0=0
. Then, the update rule is:
dpi=minimum of{dpi−1+1min(dpj)if Ai='W'for all j,where:max(0,i—m)≤j<i and Aj='L'
Solution complexity: O(nm)
.
*/
