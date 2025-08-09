
// https://leetcode.com/problems/find-eventual-safe-states/description/
class Solution {
public:

    bool isSafe(vector<vector<int>> &graph,vector<bool>&visited, unordered_map<int,bool> &safe, int index){
        if(visited[index]){
            return safe[index];
        }

        visited[index] = true;
        bool localDecision = true;
        for(int i : graph[index]){
            localDecision = localDecision & isSafe(graph, visited, safe, i);
        }

        // cout << "safe " << index << ": " << localDecision << endl;
        return safe[index] = localDecision;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> safe;
        for(int i=0; i<graph.size(); i++){
            if(graph[i].size() == 0){
                safe[i] = true;
            }else{
                safe[i] = false;
            }
        }

        vector<bool> visited(graph.size(), false);
        vector<int> ans;

        for(int i=0; i<graph.size(); i++){
            if(!visited[i]){
                isSafe(graph, visited, safe, i);
            }
        }

        for(auto entry : safe){
            //cout << "first: " << entry.first << " second: " << entry.second << endl;
            if(entry.second){
                ans.push_back(entry.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// crust is that no cycle is possible
// every part of cycle will not be included into the safe node
// https://leetcode.com/problems/find-eventual-safe-states/submissions/1118281015/


// topo sort implementation
vector<int> eventualSafeNodes(vector<vector<int>>& G) {
    int N = G.size();
    vector<vector<int>> R(N);
    vector<int> outdegree(N), safe(N), ans;
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        for (int v : G[i]) {
            R[v].push_back(i);
        }
        outdegree[i] = G[i].size();
        if (outdegree[i] == 0) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        safe[u] = 1;
        for (int v : R[u]) {
            if (--outdegree[v] == 0) q.push(v);
        }
    }
    for (int i = 0; i < N; ++i) {
        if (safe[i]) ans.push_back(i);
    }
    return ans;
}

// ==================================

class Solution {

private:
    bool dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &pathVisited, vector<int> &safeStates){
        visited[node] = true;
        pathVisited[node] = true;


        for(int nei: adj[node]){
            if(!visited[nei]){
                if(dfs(adj, nei, visited, pathVisited, safeStates) == true){
                    return true;
                }
            } // visited is true
            else if(pathVisited[nei]){
                return true;
            }
        }

        // no loop detected for node
        safeStates.push_back(node);
        pathVisited[node] = false;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // if loop is detected, all the elements of the loop will not be part of safe state

        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false);

        vector<int> safeStates;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(graph, i, visited, pathVisited, safeStates);
            }

        }

        sort(safeStates.begin(), safeStates.end());

        return safeStates;
    }
};