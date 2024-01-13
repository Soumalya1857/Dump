class Solution {
// TLE
private:
    int dfs(vector<vector<int>> &adj, int x, string colors, vector<bool> &visited, vector<bool> &pathVisited,  unordered_map<char,int> count){
        int ans = 0;

        if(pathVisited[x]){
            return -1;
        }

        visited[x] = true;
        pathVisited[x] = true;

        count[colors[x]]++; // color incremented
        // if terminal calculate

        if(adj[x].size() == 0){
            // loop over colors
            for(auto entry : count){
                ans = max(ans, entry.second);
            }
        }

        // else
        for(int nei : adj[x]){
            int temp = dfs(adj, nei, colors, visited, pathVisited, count);
            if(temp == -1) return -1; // loop detected

            ans = max(ans, temp);
        }

        pathVisited[x] = false;
        return ans;

    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.length();
        vector<vector<int>> adj(N);

        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(N, false);

        int ans = -1;
        for(int i=0; i<N; i++){
            int temp = -1;
            if(!visited[i]){
                vector<bool> pathVisited(N,false);
                unordered_map<char, int> count;
                temp = dfs(adj, i, colors, visited, pathVisited, count);
                if(temp == -1){
                    return -1;
                }
            }

            ans = max(ans, temp);
        }

        return ans;
    }
};