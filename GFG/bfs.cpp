#include<bits/stdc++.h>
using namespace std;

bool visited[n]= {false};
vector<vector<int> >graph;

int bfs(int u)
{
    int layer = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        visited[curr] = true;
        //layer++;
        //check weather its a leaf node
        // return layer

        for(int i=0;i<graph[curr].size();i++)
        {
            q.push(graph[curr][i]);
            if(visited[graph[curr][i]] == false)
                visited[graph[curr][i]] = true;
        }
        
    }
}

int main()
{
    int i,j,k,n;
    cin >> n;//number of vertices
    
    int edges;
    cin >> edges;
    for(i=0;i<edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    return 0;
}