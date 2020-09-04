#include <iostream>
#include <algorithm>
#include <map>
#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {
	//code
	
	ll tc;
	cin >> tc;
	while(tc--)
	{
	    ll n,i,j;
	    cin >> n;
	    ll sum = 0;
	    ll a[n];
	   // unordered_map<ll,ll> m;
	    //for(i=0;i<n;i++) cin >> a[i], sum += a[i];
	    for(i=0;i<n;i++)
	    {
	        cin >> a[i];
	        sum += a[i];
	        //m[a[i]]++;
	       // pre[i] = sum;
	       // m[sum]++;
	    }
	    
	    if(n==1 || sum % 2 == 1) cout << "NO\n";
	    else
	    {
	       sum /= 2;
	       bool dp[n+1][sum+1];
	       // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
        
        
	       for(i=1;i<=n;i++)
	       {
	            for(j=1;j<=sum;j++)
	            {
	                if(a[i-1] > sum) dp[i][j] = dp[i-1][j];
	                else if(a[i-1] <= j)
	                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
	            }
	       }
	       
	       if(dp[n][sum]) cout << "YES\n";
	       else cout << "NO\n";
	    }
	    
	    
	    
	}
	return 0;
}

/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
*/