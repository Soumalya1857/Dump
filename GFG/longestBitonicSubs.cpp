#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         int a[n];
//         int i,j;
//         for(i=0;i<n;i++) cin >> a[i];
//         int length = 1, maxLen = -1;
//         bool state = false;// false means increasing true means we encounted a decreasing sequence once
//         //bool dp[n][2] = {false};

//         //dp[0][0] = true;
//         for(i=1;i<n;i++)
//         {
//             if(a[i] > a[i-1] && state == false)
//             {
//                 length++;
//             }
//             else if(a[i] < a[i-1] && state == false)
//             {
//                 state = true;
//                 length++;
//             }
//             else if(a[i] > a[i-1] && state == true) // need to reset
//             {
//                 state == false;
//                 length = 2;
//             }
//             else if(a[i] < a[i-1] && state == true)// encounted decrease only once
//             {
//                 length++;
//             }

//             maxLen = max(length, maxLen);
//         }
        
//         cout << maxLen << "\n";
//     }
//     return 0;
// }



int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,i,j;
        cin >> n;
        int a[n];
        for(i=0;i<n;i++) cin >> a[i];

        int increase[n], decrease[n];
        // increase[0] = 1;
        // decrease[0] = 1;
        for(i=0;i<n;i++) increase[i] = 1, decrease[i] = 1;

        // create a longest increasing subsequence ending at a[i]
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i] > a[j] && increase[i] < increase[j] + 1)
                {
                    increase[i] = increase[j]+1;
                }
            }
        }

        // create longest decresing subsequence starting at a[i]
        for(i=n-2;i>=0;i--)
        {
            for(j=n-1;j>i;j--)
            {
                if(a[i] > a[j] && decrease[i] < decrease[j] + 1)
                {
                    decrease[i] = decrease[j]+1;
                }
            }
        }

        // need to return max value of increase[i] + decrese[i] -1
        int maxi = -1;
        for(i=0;i<n;i++)
        {
            maxi = max(maxi, increase[i] + decrease[i] -1);
        }

        cout << maxi << "\n";
    }
    return 0;
}
/*****
 * 
 * https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence
 * 
 * ***/