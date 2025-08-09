// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        
        vector<int> ans;
        unordered_map<int,int> um;
        int count = 0;
        for(int i=0;i<k;i++)
        {
            if(um[A[i]] == 0) count++;
            um[A[i]]++;
        }
        
        ans.push_back(count);
        
        for(int i=k;i<n;i++)
        {
            if(um[A[i]] == 0) count++;
            um[A[i]]++;
            
            um[A[i-k]]--;
            if(um[A[i-k]] == 0) count--;
            
            ans.push_back(count);
        }
            
        return ans;
    }
};

// prb: https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends