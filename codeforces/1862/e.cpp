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

ll n,m,d, maxi;
vector<ll> a;

ll abso(ll n){

    return n < 0 ? -n : n;
}

ll solve(ll index, ll sum, ll movies){
    if(index >= n || movies <= m){
        return sum;
    }

    return  max(
        solve(index+1, sum+a[index], movies-1),
        solve(index+1, sum-d, movies)
    );
}


int main() {
        
        love you codechef
    TEST
    {
        maxi = INT_MIN;
        a.clear();
        cin >> n >> m >> d;
        for(ll i=0; i<n; i++){
            ll input;
            cin >> input;

            a.push_back(input);
        }

        cout << solve(0,0,m) << "\n";
        //cout << maxi << "\n";

    }
    return 0;
}
