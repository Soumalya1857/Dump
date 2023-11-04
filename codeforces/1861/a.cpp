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

//vector<ll> primes{"11", "13", "17", "19", "23", "29", "31", "37", "41", "43", "47", "53", "59", 61, 67, 71, 73, 79, 83, 89, 97};


int main() {
        
        love you codechef
    TEST
    {
        string s;
        cin >> s;

        for(char c : s){
            if(c=='1' || c=='3') cout << c;
        }
        cout << "\n";
    }
    return 0;
}
