class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // dijktra's algorithm
        // treat each matrix as intermediate matrix

        vector<vector<pair<int,int>>> adj(n+1);
        // vector<int> dist(n+1, INT_MAX);

        vector<bool> visited(n+1, false);
        int minVal = INT_MAX;
        for(vector<int> road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        stack<pair<int,int>> q;

        q.push({1,INT_MAX}); // min path val

        while(!q.empty()){
            pair<int,int> curr = q.top(); q.pop();

            minVal = min(minVal, curr.second);

            visited[curr.first] = true;

            for(pair<int,int> nei : adj[curr.first]){
                if(!visited[nei.first]){
                    q.push({nei.first, min(nei.second, curr.second)});
                }
            }
        }

        return minVal;

        // while(!q.empty()){
        //     int currDist = q.front().second;
        //     int currNode = q.front().first;

        //     q.pop();

        //     if(dist[currNode] > currDist){
        //         dist[currNode] = currDist;
        //     }

        //     for(pair<int,int> nei : adj[currNode]){
        //         if(dist[nei.first] >= currDist + nei.second){
        //             q.push({nei.first, currDist + nei.second});
        //         }
        //     }
        // }


       // return dist[n];



    }
};

// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/submissions/1150682686/
