#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll abs(ll n)
{
    return (n<0)? -n : n;
}

int main() {
	//code
	
	ll tc;
	cin >> tc;
	while(tc--)
	{
	    ll n,k;
	    cin >> n >> k;
	    int mod[n];
	    for(int i=0;i<n;i++)
	    {
	        int temp;
	        cin >> temp;
	        if(temp<0)
	        {
	            mod[i] = (((abs(temp)/k)+1)*k + temp)%k;
	        }
	        else mod[i] = temp%k;
	    }
	    
	    
	    int s = 0, ans = 0;
	    unordered_multimap<int,int> m;
	    for(ll i=0;i<n;i++)
	    {
	        s += mod[i];
	        s = s % k;
	        
	        m.insert({s,i});
	        
	        if(s==0) ans = max(ans, i+1);
	        
	        //if(m.find(s) == m.end()) m[s] = i;
	        
	       // if(m.find(k-s) != m.end()) 
	       //     ans = max(ans, i-m[k-s]);
	       
	       auto itr = m.equal_range(s);
	       for(auto it = itr.first; it != itr.second;it++)
	       {
	           int temp = i - it->second;
	           ans = max(temp,ans);
	       }
	    }
	  
	    cout << ans << "\n";
	}
	return 0;
}

/*
https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k/0/
*/



unordered_map<int,int> m;
        int sum = 0;
        int index = 0;
        int len = 0;

        for(int i=0;i<n;i++){
            sum+=a[i];
            int y=(sum%k+k)%k;
            if(y==0){
                len = i+1;
            }

            if(m.find(y)==m.end()){
                m[y] = i;
            }

            if(m.find(y)!=m.end()){
                int index = i-m[y];
                len = max(len,(index));
            }
        }
        cout<<len<<endl;