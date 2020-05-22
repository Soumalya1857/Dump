#include<bits/stdtr1c++.h>
using namespace std;

int main()
{

    int i,j,k, n,num;//n number of vertices,num = edges
    cin >> n >> num;
    //int adj[n+1][n+1];
    vector<vector<int> > adj;

    for(i=0;i<num;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    int dist[n];
    bool pathSet[n];
    int src;
    cin >> src;
    for(i=0;i<n;i++) 
    {
        if(i==src) dist[src]= 0;
        else {dist[i] = INT_MAX;pathSet[i] = false;}
    }

    int curr = src;
    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[curr].size();j++)
        {
            //dist[i] = min(adj[src][curr]+adj[curr],adj[curr][curr]);
        }
    }



    
    return 0;
}

/***********
 * 
 * const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

p tracks the parent
d tracks the distance
u tracks weather its included or not
********/