#include<bits/stdc++.h>
using namespace std;

int result = 0;

void findMax(int currNode, int prevNode, vector<vector<int>> &adj, vector<int> &value){


    int maximumBranchSum1 = 0;
    int maximumBranchSum2 = 0;

    for(int i=0; i<adj[currNode].size(); i++){
        if(adj[currNode][i] == prevNode){
            continue;
        }

        findMax(adj[currNode][i], currNode, adj, value);

        if(value[adj[currNode][i]] > maximumBranchSum1){
            maximumBranchSum2 = maximumBranchSum1;
            maximumBranchSum1 = value[adj[currNode][i]];
        } else{
            maximumBranchSum2 = max(maximumBranchSum2, value[adj[currNode][i]]);
        }

    }

    result = max(result, value[currNode] + maximumBranchSum1+ maximumBranchSum2);

    value[currNode] += maximumBranchSum1;

}

int solve(vector<int> parent, vector<int> value){
    int N = value.size();
    vector<vector<int>> adj(N+1);

    for(int i=0; i<parent.size(); i++){
        if(parent[i] != -1){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
    }

    // adj done
    findMax(0,-1, adj, value);

    return result;
}

int main(){

    vector<int> parent = {-1,0,1,2,0,5};
    vector<int> value = {-2,10,10,-3,10};

    cout << solve(parent, value) << endl;

}