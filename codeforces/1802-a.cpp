// https://codeforces.com/problemset/problem/1717/C

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
        ll n; cin >> n;
        ll b[n];
        ll positive = 0, negative = 0;
        for(int i=0; i<n;i++) {
            ll input;
            cin >> input;
            ll temp = input > 0 ? ++positive : ++negative;
        }

        ll ans = 0;
        for(ll i = 0; i < positive; i++){
            cout << ++ans << " ";
        }

        for(int i=0; i<negative; i++){
            cout << --ans << " ";
        }

        cout << "\n";

        ans = 0;
        while(negative--){
            cout << "1" << " " << "0" << " ";
            positive--;
        }

        for(int i=0; i<positive;i++){
            cout << ++ans << " ";
        }

        cout << "\n";

    }
	return 0;
}
