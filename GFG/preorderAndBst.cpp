#include<bits/stdc++.h>
using namespace std;


bool canRepresentBST(int pre[], int n) 
{ 
    // Create an empty stack 
    stack<int> s; 
  
    // Initialize current root as minimum possible 
    // value 
    int root = INT_MIN; 
  
    // Traverse given array 
    for (int i=0; i<n; i++) 
    { 
        // If we find a node who is on right side 
        // and smaller than root, return false 
        if (pre[i] < root) 
            return false; 
  
        // If pre[i] is in right subtree of stack top, 
        // Keep removing items smaller than pre[i] 
        // and make the last removed item as new 
        // root. 
        while (!s.empty() && s.top()<pre[i]) 
        { 
            root = s.top(); 
            s.pop(); 
        } 
  
        // At this point either stack is empty or 
        // pre[i] is smaller than root, push pre[i] 
        s.push(pre[i]); 
    } 
    return true; 
} 


int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,i,j;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++) cin >> arr[i];

        // left child = 2*i+1
        // right child = 2*i + 2
        // both has to be lesser than the root
        bool ans = canRepresentBST(arr,n);
        cout << ans << "\n";
        
    }
    return 0;
}

/****
 * https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0
 * **/


/*****
 * solution  https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
 * ****/