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
        int n;
        cin >> n;
        int known = 0, unknown = 0;
        int need = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 1) ++unknown;
            else {
                known += unknown;
                unknown = 0;
            }
            need = max(need, unknown + (known ? known / 2 + 1 : 0));
    }
    cout << need << endl;

    }
	return 0;
}
