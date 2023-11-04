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
        ll a[n], b[n];

        // differece in consequtive elements in b should not exceed 2
        for(ll i=0;i<n;i++) cin >> a[i];
        for(ll i=0;i<n;i++) cin >> b[i];

        bool flag = true;
        for (ll i=0; i<n;i++){
            flag &= (a[i] <= b[i]); // if equal it becomes 1, otherwise 0
            if(a[i] < b[i]) flag &= (b[i] - b[(i+1)%n]) <= 1 ;
        }

        cout << (flag ? "Yes" :"No") << "\n" ;

    }
	return 0;
}
