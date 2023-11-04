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


// int main() {
        
//         love you codechef
//     TEST
//     {
//         ll n;
//         cin >> n;
        
//         ll b[n];
//         vector<ll> odd, even;
//         for(ll i=0; i<n;i++){
//             cin >> b[i];
//             if(b[i]%2 == 0) even.push_back(b[i]);
//             else odd.push_back(b[i]);
//         }

//         sort(odd.begin(), odd.end(), greater<ll>());
//         sort(even.begin(), even.end(),greater<ll>());

//         for(ll i=0; i<n; i++){
//             if(b[i]%2==1) {
//                 b[i] = odd[odd.size()-1];
//                 odd.pop_back();
//             }
//             else{
//                 b[i] = even[even.size()-1];
//                 even.pop_back();
//             }
//         }
//         bool flag = true;
//         for(ll i=0; i<n-1;i++){
//             if(b[i] > b[i+1]) {
//                 flag = false;
//                 break;
//             }
//         }

//         if(flag){
//             cout << "YES" << endl;
//         } else{
//             cout << "NO" << endl;
//         }


//     }
//     return 0;
// }

int main() {
        
        love you codechef
    TEST
    {
        ll n;
        cin >> n;
        
        ll b[n],c[n];
        vector<ll> odd, even;
        for(ll i=0; i<n;i++){
            cin >> b[i];
            c[i] = b[i];
        }

        sort(c, c+n);

        bool flag = true;
        for(ll i=0; i<n;i++){
            if(b[i]%2 != c[i]%2) {
                flag = false;
                break;
            }
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
