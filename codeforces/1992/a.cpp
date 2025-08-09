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

int main() {

        love you codechef
    TEST
    {
        int a,b,c;
        cin >> a >> b >> c;

        ll maxi = INT_MIN;

        for(ll i=0; i<=5; i++){
            for(ll j=0; j<=5; j++){
                for(ll k=0; k<=5; k++){
                    if(i+j+k <= 5){
                        maxi = max(maxi, (a+i)*(b+j)*(c+k));
                    }
                }
            }
        }

        cout << maxi << endl;
    }
	return 0;
}
