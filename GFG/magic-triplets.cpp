#include <iostream>
using namespace std;
#define ll long long int

int main() {
	//code
	ll tc;
	cin >> tc;
	while(tc--)
	{
	    ll n;
	    cin >> n;
	    int a[n];
	    ll i,ans = 0;
	    for(i=0;i<n;i++) cin >> a[i];
	    
	    for(i=0;i<n;i++)
	    {
	        ll j,k;
	        ll less = 0, more = 0;
	        for(j = i-1;j>=0;j--)
	        {
	            if(a[j] < a[i]) less++;
	        }
	        
	        for(k = i+1;k<n;k++) if(a[k] > a[i]) more++;
	        
	        ans += more*less;
	    }
	    
	    cout << ans << endl;
	    
	    
	}
	
	
	return 0;
}

/*
https://practice.geeksforgeeks.org/problems/magic-triplets/0
*/