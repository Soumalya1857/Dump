#include <iostream>
using namespace std;
#define ll long long int

int main() {
	//code
	
	ll tc;
	cin >> tc;
	while(tc--)
	{
	    ll n,count=-1;
	    cin >> n;
	    ll a[n]; // basically prefix array
	    for(ll i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
	    
	    
	    if(n==1) cout << "1\n";
	    else
	    {
	        ll pre[n];
	    ll suf[n];
	    pre[0] = a[0];
	    suf[n-1] = a[n-1];
	    for(ll i =1;i<n;i++)
	    {
	        pre[i] = pre[i-1]+a[i];
	        suf[n-i-1] = suf[n-i]+a[n-i-1];
	    }
	    
	    
	    for(ll i=0;i<n;i++)
	    {
	        if(pre[i] == suf[i] /*&& 2*(i+1) == n+1*/) {count = i; break;}
	    }
	    
	   //  cout << "pre: ";
	   //  for(ll i=0;i<n;i++) cout<<pre[i] << " ";
	   //  cout << "\n";
	     
	   //  cout << "suf: ";
	   //  for(ll i=0;i<n;i++) cout<<suf[i] << " ";
	   //  cout << "\n";
	     
	    
	    if(count == -1) cout << "-1\n";
	    else cout << count+1 << endl;
	    
	    //cout << "##################################\n";
	    }
	}
	
	return 0;
}


/*
https://practice.geeksforgeeks.org/problems/equilibrium-point/0
*/