#include <iostream>
using namespace std;
#define ll long long int

int main() {
	//code
	
	ll tc;
	cin>> tc;
	while(tc--)
	{
	    ll n;
	    cin>>n;
	    int a[n];
	    ll count1 = 0;
	    
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	        if(a[i] == 1) count1++,a[i] = -1;
	        else if(a[i] == 0) a[i] = 1;
	    }
	    
	    // now need to calculate kadenes algorithm
	    // max contigulus subarr
	    
	    ll max_sum_so_far = 0;
	    ll max_ending_here = 0;
	    for(int i=0;i<n;i++)
	    {
	        //int temp = max_sum;
	        max_ending_here += a[i];
	        if(max_sum_so_far < max_ending_here) max_sum_so_far = max_ending_here;
	        if(max_ending_here<0) max_ending_here = 0;
	        
	        //ans = max(ans, max_sum);
	    }
	    //cout << "ans: " << max_sum_so_far << " count1: " << count1 << "\n";
	    
	    cout << count1+max_sum_so_far << "\n";
	}
	return 0;
}

/*
https://practice.geeksforgeeks.org/problems/flip-bits/0
*/