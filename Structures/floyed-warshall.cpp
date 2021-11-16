#include<iostream>
using namespace std;



void solve(vector<vector<int>> roads, vector<vector<int>>queries)
{
    long long dist[n+1][n+1] = {INT_MAX}; // not to get a overflow due to INT_MAX;

    // floyed warshall
    for(int k = 1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]); // intermediate is k
            }
        }
    }

    for(auto query: queries)
    {
        
    }


}

