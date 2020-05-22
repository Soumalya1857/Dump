#include<bits/stdc++.h>
using namespace std;
//#define n 4
#define INF 500

int main()
{
    register int i,j;
    int n=4;
    //cin >> n;
    //int graph[n+1][n+1];

    int graph[5][5] = {
        {0,0,0,0,0},
        {0,0, 5, INF, 10},  
        {0,INF, 0, 3, INF},  
        {0,INF, INF, 0, 1},  
        {0,INF, INF, INF, 0}
    };

    // for(i=1;i<=n;i++)
    //     for(j=1;j<=n;j++)
    //         graph[i][j] = 500;

    // int r;
    // cin >> r;
    // for(int i=0;i<r;i++)
    // {
    //     int u,v,w;
    //     cin >> u >> v >> w;
    //     graph[u][v] = w;
    // }

    for(int k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                graph[i][j] = min(graph[i][j],(graph[i][k]+graph[k][j]));
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(graph[i][j]==500) cout << "INF\t";
            else cout << graph[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}