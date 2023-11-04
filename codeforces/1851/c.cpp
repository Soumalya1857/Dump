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
        // last of first color er por atleast k of last color
        ll n,k;
        cin >> n >> k;

        ll c[n];
        for(ll i=0; i<n; i++){
            cin >> c[i];
        }

        ll first = c[0], last = c[n-1], firstCount = 0, lastCount = 0, firstPlace = 0;

        // edge: if first == last

        for(ll i=0; i<n;i++){
           if(c[i] == first) {
                firstCount++;
                firstPlace = i;
            }

            if(c[i] == last && firstCount >= k) lastCount++;
        }

        if(first == last && firstCount >= k) cout << "YES\n";
        else{

            // for(ll i=firstPlace; i<n; i++){
            //     if(c[i] == last) lastCount++;
            // }

            // if(lastCount >= k && firstCount >=k) cout << "YES\n";
            // else cout << "NO\n";

            if(firstCount >= k && lastCount >= k){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}
