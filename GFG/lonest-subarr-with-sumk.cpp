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
        ll n,sum;
        cin >> n >> sum;
        int a[n];
        for(ll i=0;i<n;i++) cin >> a[i];
        
        int ans = 0;
        unordered_map<int,int> m;
        
        
        
        m[0] = -1;
        int s = 0;
        for(int i=0;i<n;i++)
        {
            s+= a[i];
            if(m.find(s) == m.end()){ 
                m[s] = i;
            }
            if(m.find(s-sum) != m.end()) 
                {
                    ans = max(ans, i-m[s-sum]);
                }
        }
        
        cout << ans << endl;
    }
	return 0;
}

/*
https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k/0
*/