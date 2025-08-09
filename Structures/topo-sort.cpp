#include<iostream>
using namespace std;



void toposort(vector<vector<int>> graph, vector<bool> visited, stack<int>s, int start)
{
    visited[start] = true;

    for(int nei : graph[start])
    {
        if(!visited[nei])
             toposort(graph, visited, s, nei); //' this dfs will make sure i have visited all the child nodes and they are pushed into the stack as well
    }

    s.push(start);
}

vector<int> topoSortStart(vector<vector<int>>&graph, int n){

    stack<int>s;
    vector<bool>visited(n,false);

    for(int x : visited)
    {
        if(!visited[x])
        {
            toposort(graph, visited, s, x); // for all unvisited node start toposort
        }
    }

    // now our stack contains all the nodes in reverse order
    vector<int> ans;

    while(!s.empty()) ans.push_back(s.top()), s.pop();

    return ans; 
}

int main()
{
    return 0;
}