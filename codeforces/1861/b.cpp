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
        string a,b;
        cin >> a >> b;
\
        ll left0=-1, left1=-1, right0=-1, right1=-1; char val='a', val0='a', val1='a';
        bool updated0 = false, updated1=false;
        for(ll i=1; i<a.length()-1;i++){
            if(a[i] == b[i] && a[i]=='0' && !updated0) {
                left0=i;
                val0=a[i];
                updated0 = true;
            }

            if(a[i] == b[i] && a[i]=='1' && !updated1) {
                left1=i;
                val1=a[i];
                updated1 = true;
            }

            if(updated0 && updated1) break;
            
        }

        updated0=false, updated1=false;

        for(ll i=a.length()-1; i>0;i--){
            if(a[i] == b[i]) {
                inside the inityial because 
            }