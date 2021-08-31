class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], vector<bool>&visited, vector<bool>&dfsVisited, int node)
    {
        
        visited[node] = true;
        dfsVisited[node] = true;
        
        
        for(auto x : adj[node])
        {
            if(!visited[x])
            {
                if(dfs(adj, visited, dfsVisited, x)) 
                    return true;
            }
            else if(dfsVisited[x]) return true; // x previously visited and my dfs also visits this => cycle
        }
    
        
        
        dfsVisited[node] = false;
        return false;
            
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<bool>visited(V,false);
        vector<bool> dfsVisited(V,false);
        
        // stack<int>s;
        // s.push(0);
        // bool cyclic = false;
        // while(!s.empty())
        // {
        //     int curr = s.top();s.pop();
            
        //     if(visited[curr])
        //     {
        //         cyclic = true;
        //         break;
        //     }
            
        //     visited[curr] = true;
        //     for(auto x : adj[curr])
        //     {
        //         s.push(x);
        //     }
        // }
        
        // return cyclic;
        
        
        // normal dfs won't work over here directed cycle 
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                if(dfs(adj, visited, dfsVisited, i)) 
                return true;
        }
        
        return false;
        
    }
};
// prb: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// soln: https://www.youtube.com/watch?v=uzVUw90ZFIg