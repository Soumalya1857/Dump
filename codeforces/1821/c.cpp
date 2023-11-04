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
        string s;
        cin >> s;
        unordered_map<char, vector<ll>> map;

        for(ll i=0; i<s.size(); i++){
            map[s[i]].push_back(i);
        }

        ll ansGlobal = INT_MAX;
        

        for(auto entry : map){
            vector<ll> temp = entry.second;
            ll ans = 0;
            ans = max(ans, (ll)ceil(log2(temp[0]+1)));
            ans = max(ans, (ll)ceil(log2(s.size() - temp[temp.size()-1])));

            for(ll i=0; i<temp.size()-1; i++){

                // initial
                // if(i==0){
                //     if(temp[0] >= 1) ans = max(ans, (ll)ceil(log2(temp[0]+1)));
                //     if(s.size() - temp[temp.size()-1] >= 1) ans = max(ans, (ll)ceil(log2(s.size() - temp[temp.size()-1])));
                // }

                ans = max(ans, (ll)ceil(log2(temp[i+1]-temp[i])));
            }

            ansGlobal = min(ansGlobal, ans);
        }


        cout << ansGlobal << "\n";
    }
    return 0;
}
