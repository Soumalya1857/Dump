/*
https://practice.geeksforgeeks.org/problems/special-keyboard/0
*/

#include <bits/stdc++.h>
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
	    if(n <=6) cout << n << endl;
	    else if(n>75) cout << "-1\n";
	    else
	    {
	        ll screen[n+1];
	        for(int i=1;i<=6;i++) screen[i-1] = i;
	        
	        for(int i=7;i<=n;i++)
	        {
	            
	            // for any keystroke n, we will need to choose between:- 
        // 1. pressing Ctrl-V once after copying the 
        // A's obtained by n-3 keystrokes. 
  
        // 2. pressing Ctrl-V twice after copying the A's 
        // obtained by n-4 keystrokes. 
  
        // 3. pressing Ctrl-V thrice after copying the A's 
        // obtained by n-5 keystrokes. 
	            screen[i-1] = max(2*screen[i-4], max(3*screen[i-5],4*screen[i-6]));
	        }
	        
	        cout << screen[n-1] << endl;
	    }
	}
	return 0;
}

/*
thats a nice question and totally got me
*/