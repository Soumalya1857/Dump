class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n,false);

        int ans = dfs(adj, hasApple, n, visited, 0);
    
        return ans;
    }

    int dfs(vector<vector<int>> &adj, vector<bool> &hasApple, int n, vector<bool> &visited, int curr){
        if(visited[curr]) 
            return 0;

        visited[curr] = true;
        int localAns = 0;
        if(hasApple[curr] && curr !=0 ) localAns += 2; // if root has apple => already collected
        bool isAlreadyAdded = false;
        // if all the adjacent are visited return 0
        for(int i=0; i<adj[curr].size(); i++){
            int temp = dfs(adj, hasApple, n, visited, adj[curr][i]);
            if(temp != 0){
                localAns += temp;
                if(!isAlreadyAdded && !hasApple[curr] && curr != 0){
                    localAns += 2;
                    isAlreadyAdded = true;
                }
            }

        }
        //cout << "local: " << localAns << " curr: " << curr << endl;
        return localAns;
    }
};

// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/1110274331/