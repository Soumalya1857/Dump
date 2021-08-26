#include<iostream>
using namespace std;



// initialize the rank and parent array
void makeSet(vector<int>&parent, vector<int>&rank, int n) // no of elements
{
    parent = vector<int> (n+1); 
    rank = vector<int> (n,0); // initially all the ranks are 0

    for(int i=1;i<=n;i++)
        parent[i] = i;
}

void union(int u, int v)
{   
    u = findParent(u);
    v = findParent(v);

    if(rank[u] > rank[v]) // take v and attach it to u
    {
        parent[v]  = u;
    }
    else if(rank[v]> rank[u]) {
        parent[u] = v;
    }
    else if(rank[v] == rank[u])
    {
        rank[u]++;
        parent[v] = u;
    }
}

int findParent(int u)
{
    if(parent[u] == u) 
        return u;

    return parent[u] = findParent(parent[u]);
}

int main()
{

    vector<int> parent, rank;
    makeSet(parent, rank, 1000); // populate the array
    return 0;
}