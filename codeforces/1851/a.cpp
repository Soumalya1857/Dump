// https://codeforces.com/problemset/problem/1802/C

#include<bits/stdc++.h>
#include <cstdlib>

#define ll long long
#define ull unsigned long long
#define ld long double
#define MOD 1000000007

#define love ios_base::sync_with_stdio(false);
#define you cin.tie(NULL);
#define codechef cout.tie(NULL);
#define TEST ll test; cin >> test; while(test--)

using namespace std;

ll mod(ll n){

    return n < 0 ? -n : n;
}


int main() {
        
        love you codechef
    TEST
    {
        ll n,m,k,H, ans=0;

        cin >> n >> m >> k >> H;

        for(int i=0; i<n; i++) {
            ll input;
            cin >> input;
            ll tmp = mod(input-H);

            if(tmp%k == 0 && tmp/k< m && tmp/k > 0) ++ans;
        }

        cout << ans << endl;

    }
    return 0;
}
