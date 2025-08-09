#include <iostream>
#define ll long long int
using namespace std;

int main() {
	//code
	
    ll t;
    cin>> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll c,sum = 0;
        for(ll i=0;i<n-1;i++)
        {
            cin >> c;
            sum += c;
        }
        ll ans = (n*(n+1))/2 - sum;
        cout << ans << "\n";
    }
	
	return 0;
}

// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

// another approach
#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int miss = 0;
    for(int i=1;i<n;i++)
    {
      int x;
      cin>>x;
      miss^=(x^i);
    }
    miss^=n;
    cout<<miss<<"\n";
  }
  return 0;
}
/*
1) XOR ALL THE ARRAY ELEMENT...BE IT X1
2) XOR ALL ELEMENT FROM 1...n...BE IT X2
3) ANS IS X1^X2
*/