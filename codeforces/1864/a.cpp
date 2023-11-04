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

ll abso(ll n){

    return n < 0 ? -n : n;
}


int main() {
        
        love you codechef
    TEST
    {
        ll x,y,n;
        cin >> x >> y >> n;
        vector<ll> arr;

        if( y - (n-1) - ((n-2)*(n-1))/2  < x) cout << -1 << "\n";
        else{
            ll d =1;
            // arr.push_back(y);
            cout << x << " ";
            
            for(ll i = n-2; i>=1; i--){
                cout << (y-i-(i*(i-1)/2)) << " ";
            }

            cout << y << " ";

            // arr.push_back(x);
            // for(ll i=arr.size()-1; i>=0; i--){
            //     cout << arr[i] << " ";
            // }         
            cout << "\n";
        }

        

    }
    return 0;
}