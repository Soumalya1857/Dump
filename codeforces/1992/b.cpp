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
        ll n,k;
        cin >> n >> k;

        ll a[k];
        ll maxi = -1;
        bool once = true;

        for(ll i=0; i<k;i++){
            cin >> a[i];
            maxi = max(maxi, a[i]);
        }

        ll ans = 0;
        for(ll i=0; i<k; i++){
            if(a[i] == 1) ans += 1;
            else if(a[i] == maxi && once) {
                once = false;
                continue;
            }
            else {
                ans += 2*a[i] - 1;
            }
        }

        //ans -= 2*maxi - 1;

        cout << ans << endl;

    }
	return 0;
}
