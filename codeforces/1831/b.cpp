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
        ll n;
        cin >> n;
        ll a[n], b[n];

        for(ll i=0; i<n;i++){
            cin >> a[i];
        }

        for(ll i=0; i<n;i++){
            cin >> b[i];
        }


        unordered_map<ll, ll> mapA, mapB;

        ll temp = a[0], count = 1; mapA[temp] = count;

        for(ll i=1; i<n; i++){
            if(a[i] == temp){
                count++;
                mapA[temp] = max(mapA[temp], count);
            } else{
                count = 1;
                temp = a[i];
                mapA[temp] = max(mapA[temp], count);
            }
        }

        temp = b[0], count = 1; mapB[temp] = count;
        for(ll i=1; i<n; i++){
            if(b[i] == temp){
                count++;
                mapB[temp] = max(mapB[temp], count);
            } else{
                count = 1;
                temp = b[i];
                mapB[temp] = max(mapB[temp], count);
            }
        }



        ll maxi = INT_MIN;

        for(auto entry : mapA){
            if(mapB[entry.first]){
                mapA[entry.first] += mapB[entry.first];
                //mapB[entry.first] += mapA[entry.first];
            }

            maxi = max(maxi, mapA[entry.first]);

            //cout << "MapA: " << "key: " << entry.first << " value: " << entry.second << endl;
        }

        for(auto entry: mapB){
            maxi = max(maxi, mapB[entry.first]);
            //cout << "MapB: " << "key: " << entry.first << " value: " << entry.second << endl;
        }

        cout << maxi << "\n";
    }
    return 0;
}
