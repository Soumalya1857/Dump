#include<bits\stdc++.h>
using namespace std;


pair<int,int> bfs(vector<vector<int>> &adj, vector<bool> &globalVisited, int node){

    int level = 2;
    int unvisitedCount = 0, visitedCount= 0;

    queue<int> q;
    q.push(node);
    unvisitedCount++;

    while(!q.empty() && level!=0){
        int size = q.size();
        level--;
        while(size--){
            int currNode = q.front(); q.pop();
            if(globalVisited[currNode]){
                visitedCount++;
                continue;
            }else{
                unvisitedCount++;
                globalVisited[currNode]= true;
            }

            for(int nei: adj[currNode]){
                if(!globalVisited[nei]){
                    q.push(nei);
                }
            }
        }
    }


    return {unvisitedCount, visitedCount};

}
long solve(int m, int n, vector<int> g_from, vector<int> g_to){

    // build adj matrix
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }

    vector<bool> globalVisited(n, false);
    long ans = 0;

    for(int i=0; i<n; i++){
        if(!globalVisited[i]){
            pair<int,int> count = bfs(adj, globalVisited, i);
            int unvisitedCount = count.first;
            int visitedCount = count.second;

            if(m < visitedCount){
                ans = 0;
                break;
            }

            // validate that nPr is possible
            ans += nPr(m-visitedCount, unvisitedCount);

        }
    }

    return ans;
}

int main(){


}