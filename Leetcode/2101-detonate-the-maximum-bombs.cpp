class Solution {

private:
    bool isInReach(int aX, int aY, int bX, int bY, int r){
        return (long long)(aX-bX)*(aX-bX) + (long long)(aY-bY)*(aY-bY) <= (long long)r*r;
    }

    int bfs(vector<vector<int>> &adj, int N, int bomb){
        int detonated = 0;
        vector<bool> visited(N, false);
        queue<int> s;
        s.push(bomb);

        while(!s.empty()){
            int curr = s.front(); s.pop();
            detonated++;
            visited[curr] = true;

            for(int nei : adj[curr]){
                if(!visited[nei]){
                    s.push(nei);
                    visited[nei] = true; // thats good as 2 might add 3 again in queue as it was not visited then
                }
            }
        }

        //cout << "Bomb: " << bomb << " Detonated: " << detonated << endl;
        return detonated;

    }


public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int N = bombs.size();

        vector<vector<int>> adj(N);
        for(int i=0;i<N; i++){
            for(int j=0; j<N; j++){
                if(i!=j){
                    if(isInReach(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        // now start from each node and check how many you can visit
        int ans = -1;
        for(int i=0; i<N; i++){
            ans = max(ans, bfs(adj,N,i));
            if(ans == N) return ans;
        }

        return ans;
    }
};

// https://leetcode.com/problems/detonate-the-maximum-bombs/