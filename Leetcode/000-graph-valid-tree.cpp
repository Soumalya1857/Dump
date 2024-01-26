#include<bits/stdc++.h>
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        bool isCycle = false;
        stack<pair<int,int>> s; // curr, parent
        s.push({0,-1});

        while(!s.empty()){
            auto curr = s.top(); s.pop();

            visited[curr.first] = true;

            for(int nei : adj[curr.first]){
                if(nei != curr.second && !visited[nei]){
                    s.push({nei, curr.first});
                }
                if(visited[nei] && curr.second != nei){
                    return false;
                }
            }
        }

        int i;
        for(i=0; i<n; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};

// https://neetcode.io/problems/valid-tree
// soumalya.ju.cse login