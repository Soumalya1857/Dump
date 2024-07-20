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



// clean code
// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/solutions/623673/concise-explanation-with-a-picture-for-visualization/

class Solution {
public:
    unordered_map<int, vector<int>> g; // to store the graph
    unordered_map<int, bool> visited; // to stop exploring same nodes again and again.

    void createGraph(vector<vector<int>>& edges) {
      for (auto e: edges) {
        g[e[0]].push_back(e[1]); // adjecency list representation
		g[e[1]].push_back(e[0]); // adjecency list representation
      }
    }

    int dfs(int node, int myCost, vector<bool>& hasApple) {
	  if (visited[node]) {
		  return 0;
	  }
	  visited[node] = true;

      int childrenCost = 0; // cost of traversing all children.
      for (auto x: g[node]) {
        childrenCost += dfs(x, 2, hasApple);  // check recursively for all apples.
      }

      if (childrenCost == 0 && hasApple[node] == false) {
	  // If no child has apples, then we won't traverse the subtree, so cost will be zero.
	  // similarly, if current node also does not have the apple, we won't traverse this branch at all, so cost will be zero.
        return 0;
      }

	  // Children has at least one apple or the current node has an apple, so add those costs.
      return (childrenCost + myCost);
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      createGraph(edges); // construct the graph first.
      return dfs(0, 0, hasApple); // cost of reaching the root is 0. For all others, its 2.
    }
};