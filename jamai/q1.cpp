// #include <bits/stdc++.h>
// #define ll long long int
// #define pb push_back
// #define se second
// #define fi first
// #define rep(i, l, r) for (ll i = (ll)(l); i < (ll)(r); i++)
// #define repr(i, r, l) for (ll i = (ll)(r); i > (ll)(l); i--)
// #define print(v) for (const auto itr : v){cout << itr << ' ';} cout << endl;
// #define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
// #define all(p) p.begin(), p.end()
// #define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define endl "\n"
// #define mpr make_pair
// #define inf 1e18
// using namespace std;
// const ll INF = 1e18L + 5;
// const ll mod=1e9+7;
// const ll maxn = 2e5+5;
// ll ceel(ll a, ll b){if (a % b == 0)return a / b;return a / b + 1;}
// ll modneg(ll a,ll m){a = a % m;if(a<0)a=a+m;return a;}
// ll powermod(ll x, unsigned ll y, ll p){ll res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
// ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); };


// vector <ll> v;
// ll n;
// ll dp[1000][1000];

// ll calc(ll lidx,ll cidx)
// {
//     if(cidx==n and lidx<n)
//         return inf;
//     else if(cidx==n)
//         return 0;
//     // cout<<lidx<<" "<<cidx<<endl;
//     ll &ans = dp[cidx][lidx];
//     if(ans!=-1)
//         return ans;
//     ans=inf;
//     if(v[cidx]>=cidx-lidx)
//         ans=min(ans,calc(cidx+v[cidx]+1,cidx+1)+1);
//     ans=min(ans,calc(lidx,cidx+1));
//     return ans;
// }
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// ll test;
// cin>>test;
// while(test--)
// {
//     v.clear();
//     memset(dp,-1,sizeof dp);
//     cin>>n;
//     rep(i,0,n)
//     {
//         ll temp;
//         cin>>temp;
//         v.pb(temp);
//     }
//     ll ans=calc(0,0);
//     if(ans==inf)
//         cout<<"-1\n";
//     else
//         cout<<ans<<endl;
// }
// return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

#define MOD 1000000007

signed main() {
	
	int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    int dp[n1+1][n2+1][k1+1][k2+1];
    memset(dp,0,sizeof(dp));

    int ans = 0;
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            for(int k=0; k<=k1; k++){
                for(int l=0; l<=k2; l++){
                    if(i+j == 0){
                        ans = 1;
                    } else {
                        ans = 0;
                        if(i>0 && k>0)
                            ans = (ans + dp[i-1][j][k-1][k2]) % MOD; 
                        if(j>0 && l>0)
                            ans = (ans + dp[i][j-1][k1][l-1]) % MOD; 
                    }
                    dp[i][j][k][l] = ans;
                }
            }
        }
    }

    cout << dp[n1][n2][k1][k2] << "\n";
    return 0;
}