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

int main() {
        
        love you codechef
    TEST
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for(ll i=1; i<n-2; i++){
            cout << i << ' ';
            ans ^= i;
        }
        cout << ( 1<<22 ) << ' ' << (1<<23) << ' ';
        ans ^= (1<<22);
        ans ^= (1<<23);
        cout << ans << "\n";
    }
	return 0;
}

// https://codeforces.com/problemset/problem/1722/G
