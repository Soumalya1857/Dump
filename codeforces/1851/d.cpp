// // https://codeforces.com/problemset/problem/1802/C

// #include<bits/stdc++.h>
// #include <cstdlib>

// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define MOD 1000000007

// #define love ios_base::sync_with_stdio(false);
// #define you cin.tie(NULL);
// #define codechef cout.tie(NULL);
// #define TEST ll test; cin >> test; while(test--)

// using namespace std;

// ll abso(ll n){

//     return n < 0 ? -n : n;
// }


// int main() {
        
//         love you codechef
//     TEST
//     {
//         ll n; cin >> n;
//         ll a[n];

//         for(ll i=0; i<n-1; i++){
//             cin >> a[i];
//         }

//         ll maxi = n%2 ? n * ((n+1)/2) : (n/2) * (n+1);
//         //cout << "maxi: " << maxi << " n: " << n << " a[n-1]: " << a[n-2] << endl;
//         if(a[n-2] > maxi) cout << "NO\n";

//         else if(a[n-2] != maxi){
//             // last place is maxi
//             a[n-1] = maxi;
//             // check all the elements are present or not
//             unordered_map<ll,ll> um;
//             for(ll i=1; i<n;i++){
//                 um[a[i]-a[i-1]]++;
//             }

//             ll overlap = 0;
//             for(auto i : um){
//                 if(i.second > 1) overlap++;
//             }

//             if(overlap > 0) cout << "N0\n";
//             else cout << "YES\n";
//         }

//         // last place is == maxi
//         else{
//             unordered_map<ll,ll> um;
//             for(ll i=1; i<n-1;i++){
//                 um[a[i]-a[i-1]]++;
//             }

//             // if the sequence starts with 1
//             if(a[0] == 1){
//                 um[1]++;

//                 ll overlap = 0;
//                 for(auto i : um){
//                     if(i.second >= 2) overlap++;
//                 }

//                 if(overlap > 0) cout << "NO\n";
//             }

//             // normal sequence start

//             ll overlap = 0;
//             for(auto i : um){
//                 if(i.second >= 2) overlap++;
//             }

//             if(overlap > 1) cout << "NO\n";
//             else cout << "YES\n";
//         } 
//     }
//     return 0;
// }


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

int main() {
        
        love you codechef
    TEST
    {
        ll n;
        ll a[n];
        for(ll i=0; i<n-1; i++) cin >> a[i];

        
    }
    return 0;
}