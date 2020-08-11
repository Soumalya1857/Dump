class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // I need to colour the vertices
        
        // I colour with red('r') or blue('b')
        
        int n = graph.size();
        char color[n];
        for(int i=0;i<n;i++) color[i] = 'n';// for neutral color
        bool ans = false;
        set<int> skipped;
        
        color[0] = 'b';// ie blue
        for(int i=0;i<n;i++)
        {
            if(color[i] == 'n') skipped.insert(i),i++;
            for(int j=0; j< graph[i].size();j++)
            {
                int node = graph[i][j];
                if(color[i] == color[node] /*&& color[node] != 'n'*/) return false;
                else if(color[i] == 'b') 
                    color[node] = 'r';
                else if(color[i] == 'r')
                    color[node] = 'b';
                
                if(skipped.find(node) != skipped.end())
                {
                    i = node;
                    skipped.erase(node);
                }
            }
        }
        
//         for(int skip : skipped)
//         {
//             for(int j =0; j<graph[skip].size();j++)
//             {
//                 int node = graph[skip][j];
//                 if(color[skip] == color[node] /*&& color[node] != 'n'*/) return false;
//                 else if(color[skip] == 'b') 
//                     color[node] = 'r';
//                 else if(color[skip] == 'r')
//                     color[node] == 'b';
//             }
            
//         }
        
        return true;
    }
};



/*
https://leetcode.com/problems/is-graph-bipartite/
sol - 
*/




// better solution using bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        // best is to use bfs solution bro
        
        
        int n = graph.size();
        vector<int> color(n,0); // initially all colour is 0
        
        for(int i=0;i<n;i++)
        {
            if(!color[i])
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for(int j=0;j<graph[curr].size();j++)
                    {
                        if(color[graph[curr][j]] == 0)
                        {
                            color[graph[curr][j]] = -color[curr];
                            q.push(graph[curr][j]);
                        }
                        
                        else if(color[graph[curr][j]] != -color[curr])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
    
};