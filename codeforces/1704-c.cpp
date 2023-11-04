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

ll abso(ll n){
    return n<0 ? -n : n;
}

int main() {
        
        love you codechef
    TEST
    {
        ll n,m;
        cin >> n >> m;
        vector<ll> vir;
        for(ll i=0;i<m;i++){
            ll temp;
            cin >> temp;
            vir.push_back(--temp);
        }
        sort(vir.begin(), vir.end());
        vector<ll> healthy;
        // longest series of unaffected houses

        for(ll v = 0; v<vir.size(); v++){
            healthy.push_back(max ( abso( vir[v] - vir[(v+1) % vir.size()] ) - 1, 0LL ) );
        }
        // ll len = 0;
        // for(ll i=0; i<n; i++){
        //     if(!vir[i]){
        //         ++len;
        //     }
        //     else {
        //         healthy.push_back(len); 
        //         len = 0;  
        //     }
        // }
        // healthy.push_back(len); 
        // for(auto i : healthy) cout << i << " ";
        // cout << "\n";

        // if(!vir[0]){
        //     healthy[0] += healthy[healthy.size()-1];
        //     healthy.pop_back();
        // } 

        // sort and try to protect each of them
        sort(healthy.begin(), healthy.end(), greater<int>());

        // for(auto i : healthy) cout << i << " ";
        // cout << "\n";

        // ll ans = 0, threshold = 2;
        ll saved = 0;
        // for(ll i=0; i<healthy.size(); i++){
        //     bool first = true;
        //     for(auto it = healthy.begin(); it!=healthy.end(); it++){
        //         if(first && it != healthy.end()){
        //             saved += max((*it - 1),0LL);
        //             healthy.erase(it);
        //             first = false;
        //         }
        //         else {
        //             if(it != healthy.end()){
        //                 *it -= 2;
        //                 if(*it <= 0) {
        //                     healthy.erase(it, healthy.end());
        //                 }
        //             }
                    
        //         }
        //     }
        // }

        for(ll i=0; i<healthy.size(); i++){
            bool first = true;
            for(ll j=i; j<healthy.size(); j++){
                if(first){
                    saved += max(healthy[j]-1, 0LL);
                    healthy[j] -= 1;
                    first = false;
                }
                else{
                    healthy[j] -= 2;
                    if(healthy[j] <= 0) break;
                }
            }
            // cout << "Healthy: ";
            // for(auto it : healthy) cout << it<< " ";
            // cout << endl; 
        }

        cout << n-saved << "\n";
    }
	return 0;
}
