class Solution {

private:

    bool validate(vector<vector<int>> &graph,vector<int> &color){
        // each guy should have a separate colored nei
        for(int node = 0; node<graph.size(); node++){
            for(int nei : graph[node]){
                if(color[nei] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }

    void bfs(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &color){
        queue<int> q;
        q.push(node);
        int currColor=0;

        while(!q.empty()){
            int size = q.size();
            currColor = !currColor; // toggle color
            while(size--){
                int currNode = q.front(); q.pop();

                color[currNode] = currColor;
                visited[currNode] = true;
                for(int nei: graph[currNode]){
                    if(!visited[nei]){
                        q.push(nei);
                    }
                }
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // try to solve via graph coloring

        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> color(n,-1);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(graph, i, visited, color);
            }
        }

        return validate(graph, color);

    }
};

// https://leetcode.com/problems/is-graph-bipartite/
// solution via graph coloring



// a bit better solution
class Solution {

private:

    bool bfs(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &color){
        queue<int> q;
        q.push(node);
        int currColor=0;

        while(!q.empty()){
            int size = q.size();
            currColor = !currColor; // toggle color
            while(size--){
                int currNode = q.front(); q.pop();

                color[currNode] = currColor;
                visited[currNode] = true;
                for(int nei: graph[currNode]){
                    if(color[nei] == color[currNode]){
                        return false;
                    } else if(!visited[nei]){
                        q.push(nei);
                    }
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // try to solve via graph coloring

        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> color(n,-1);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(bfs(graph, i, visited, color) == false){
                    return false;
                }
            }
        }

        return true;

        //return validate(graph, color);

    }
};

// https://leetcode.com/problems/is-graph-bipartite/
// solution via graph coloring