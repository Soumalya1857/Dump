#include<bits/stdc++.h>
using namespace std;

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
        for(i=0;i<n;i++) increase[i] = a[i], decrease[i] = a[i];

        // calculate max sum for increasing subsequence ending at a[i]
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i] > a[j] && increase[i] < increase[j] + a[i])
                    increase[i] = increase[j] + a[i];
            }
        }

        for(i=n-2;i>=0;i--)
        {
            for(j=n-1; j>i; j--)
            {
                if(a[i] > a[j] && decrease[i] < decrease[j] + a[i])
                    decrease[i] = decrease[j] + a[i];
            }
        }

        int maxi = -1;
        for(i=0;i<n;i++)
        {
            //maxi = max(maxi, increase[i] + decrease[i]);
            //maxi = max(maxi, increase[i] + decrease[i]);
            if(increase[i] + decrease[i] - a[i] > maxi)
            {
                maxi = increase[i] + decrease[i] - a[i];
                // cout << i << endl;
                // cout << increase[i] << " ba " << decrease[i] << endl;
            }
        }

        cout << maxi << endl;
    }
    return 0;
}
/****
 * 
 * https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence
 * 
 * **/