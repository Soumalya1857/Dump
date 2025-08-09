#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m,i,j;
        cin >> n >> m;
        char a[n][m];
        for(i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j] == 'X')
                {
                    if(j-1 > 0)
                    {
                        if(a[i][j-1] == 'X') a[i][j] == 'O';
                    }
                    if(j+1 <= m)
                    {
                        if(a[i][j+1] == 'X') a[i][j] == 'O';
                    }
                    if(i+1 <= n)
                    {
                        if(a[i+1][j] == 'X') a[i][j] == 'O';
                    }
                    if(i-1 > 0)
                    {
                        if(a[i-1][j] == 'X') a[i][j] == 'O';
                    }
                }
            }
        }
        int count = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j] == 'X') count++;
            }
        }
        cout << count << endl;

    }
    return 0;
}