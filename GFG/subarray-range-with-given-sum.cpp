// #include <iostream>
// using namespace std;
// #define ll long long int

// int main() {
// 	//code
// 	ll tc;
// 	cin >> tc;
// 	while(tc--)
// 	{
// 	    ll n;
// 	    cin >> n;
// 	    ll a[n];
// 	    for(ll i=0;i<n;i++) cin >> a[i];
	    
// 	    ll val;
// 	    cin >> val;
// 	    ll count = 0;
// 	    ll i,j;
	    
// 	    for(i=0;i<n;i++) if(a[i] == val) count++;
	    
// 	    ll len =2;
// 	    while(len <= n)
// 	    {
// 	        // window of length len
	        
// 	        ll sum = 0;
// 	        // initial val
// 	        for(j=0;j<len;j++) sum+=a[j];
// 	        if(sum == val)
// 	            count++;
	            
// 	        for(j=len;j<n;j++)
// 	        {
// 	            sum = sum + a[j] - a[j-len];
// 	            if(sum == val) count++;
// 	        }
// 	        len++;
// 	     }
	     
// 	     cout << count << "\n";
	    
// 	}
	
// 	return 0;
// }

// code outputs TLE



#include <iostream>
#include<bits/stdc++.h>
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
	    ll a[n];
	    for(ll i=0;i<n;i++) cin >> a[i];
	    ll val,i,j;
	    cin >> val;
	    ll count = 0;
	    
	    unordered_map<int, int> m;
	    
	    
	    ll sum = 0;
	    for(i=0;i<n;i++)
	    {
	        sum = sum + a[i];
	        if(sum == val) count++;//cout << i << " eq\n";
	        
	        if(m.find(sum-val) != m.end()) count+=m[sum-val]; //cout << i << "\n";
	        m[sum]++;
	    }
	    
	    cout << count << endl;
	    //cout << "#######################################\n";
	}
	
	return 0;
}