
/******
 * 
 * 
 * Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3
 * 
 * *****/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define MOD 1000000007
#define MOD1 998244353

#define love ios_base::sync_with_stdio(false);
#define you cin.tie(NULL);
#define codechef cout.tie(NULL);
#define TEST ll test; cin >> test; while(test--)

using namespace std;

int main() 
{ 
    love you codechef
    register ll i,j;
    TEST
    {
        int n;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++) cin >> arr[n];
        ll sum;
        cin >> sum;

        //simple solution is it possible or not

        // bool dp[n+1][sum+1];//dp[i][j] stores if it is possible to reach j using arr[0...i]
        // // for(i=0;i<=n;i++)
        // // {
        // //     for(j=0;j<=sum;j++)
        // //         dp[i][j] = false;
        // // }
        // // for(i=0;i<n;i++)
        // // {
        // //     dp[i][arr[i]] = true;
        // // }
        // for(i=0;i<=n;i++) dp[i][0] = true;//sum = 0...ans = true
        // for(i=1;i<=sum;i++) dp[0][i] = false;//arr empty ans always false

        // for(i=1;i<=n;i++)
        // {
        //     for(j=1;j<=sum;j++)
        //     {
        //         if(j < arr[i-1]) dp[i][j] = dp[i-1][j]; // if sum is less than current element 
        //                             // it doesn't get included...so ans same as dp[i-1][j]
        //         if(j >= arr[i-1])
        //             dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        //             // arr[i-1] may or maynot get included
        //     }
        // }
        bool subset[n+1][sum+1]; 
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
    
    for(i=0;i<n;i++)
        {
             subset[i][arr[i]] = true;
         }
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<arr[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= arr[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-arr[i-1]]; 
       } 
     } 
   
        // uncomment this code to print table 
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }
   
        if(subset[n][sum]) cout << "hooray\n";
        else cout << "gandu\n";
    }
    return 0;
}