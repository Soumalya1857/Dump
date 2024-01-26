// Dijktra's algorithm
// dijktra me priority queue use hota hai boss

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // bfs
        vector<int> dist(n+1, 1e9);
        vector<vector<pair<int,int>>> adj(n+1); //node, time

        for(vector<int> time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }


        stack<pair<int,int>> s; // use priority queue for faster answers
        s.push({k,0});

        while(!s.empty()){
            pair<int,int> curr = s.top(); s.pop();

            if(curr.second < dist[curr.first])
                dist[curr.first] = curr.second;

            for(pair<int,int> nei : adj[curr.first]){
                if(dist[nei.first] > dist[curr.first]+ nei.second){
                    s.push({nei.first, dist[curr.first]+nei.second});
                }
            }
        }

        // cout << "dist;-------------- " << endl;
        // for(int time : dist){
        //     cout << time << " ";
        // }
        // cout << endl;

        int maxTime = -1;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

// https://leetcode.com/problems/network-delay-time/description/



// might be more optimized approach
