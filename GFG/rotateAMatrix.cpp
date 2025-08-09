#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n][n];
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin >> a[j][i];// taking input as transpose
            }
        }
        // cout << "transpose\n";
        // for(i=0;i<n;i++)
        // {
        //     for(j=0;j<n;j++)
        //     {
        //         cout << a[i][j] << " ";// taking input as transpose
        //     }
        // }
        // cout << "\n";
        // now we need to reverse the rows

        for(i=0;i<n;i++)
        {
            for(j=0;j<n/2;j++)
            {
                // swap a[i][j] and a[i][n-j-1]
                int temp = a[i][j];
                a[i][j] = a[i][n-j-1];
                a[i][n-j-1] = temp;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout << a[i][j] << " ";// taking input as transpose
            }
        }
        cout << "\n";

    }
    return 0;
}


/*****
 * 
 * https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space/0
 * ***/