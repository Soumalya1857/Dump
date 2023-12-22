// accepted but very inefficient
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n,-1);
        map<pair<int,char>, bool> visited;

        // create the adj lists
        vector<vector<int>> redAdj(n, vector<int>(n)), blueAdj(n, vector<int>(n));

        for(vector<int> edge : redEdges){
            redAdj[edge[0]].push_back(edge[1]);
        }

          for(vector<int> edge : blueEdges){
            blueAdj[edge[0]].push_back(edge[1]);
        }

        queue<pair<int,char>> q; // node, color

        q.push({0,'r'});
        q.push({0, 'b'});

        int distance = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, char> curr = q.front(); q.pop();

                visited[curr] = true;
                if(dist[curr.first] == -1){
                    dist[curr.first] = distance;
                }

                // if parent is red, traverse blue
                if(curr.second == 'r'){
                    for(int nei: blueAdj[curr.first]){
                        if(!visited[{nei,'b'}]){
                            q.push({nei, 'b'});
                        }
                    }
                }

                // vice versa
                if(curr.second == 'b'){
                    for(int nei: redAdj[curr.first]){
                        if(!visited[{nei,'r'}]){
                            q.push({nei, 'r'});
                        }
                    }
                }
            }

            distance++;

        }

        return dist;
    }
};

// https://leetcode.com/problems/shortest-path-with-alternating-colors/

// bfs with better visited array
// gives a better solution

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n,-1);
        //map<pair<int,char>, bool> visited;

        // array instead of map
        vector<vector<bool>> visited(n, vector<bool>(2,false)); // 0 for r, 1 for b

        // create the adj lists
        vector<vector<int>> redAdj(n, vector<int>(n)), blueAdj(n, vector<int>(n));

        for(vector<int> edge : redEdges){
            redAdj[edge[0]].push_back(edge[1]);
        }

          for(vector<int> edge : blueEdges){
            blueAdj[edge[0]].push_back(edge[1]);
        }

        queue<pair<int,char>> q; // node, color

        q.push({0,'r'});
        q.push({0, 'b'});

        int distance = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, char> curr = q.front(); q.pop();

                int temp = curr.second == 'r'? 0 : 1;
                visited[curr.first][temp] = true;
                if(dist[curr.first] == -1){
                    dist[curr.first] = distance;
                }

                // if parent is red, traverse blue
                if(curr.second == 'r'){
                    for(int nei: blueAdj[curr.first]){
                        if(!visited[nei][1]){
                            q.push({nei, 'b'});
                        }
                    }
                }

                // vice versa
                if(curr.second == 'b'){
                    for(int nei: redAdj[curr.first]){
                        if(!visited[nei][0]){
                            q.push({nei, 'r'});
                        }
                    }
                }
            }

            distance++;

        }

        return dist;
    }
};

// https://leetcode.com/problems/shortest-path-with-alternating-colors/



// still not fast wnough
// same solution
class Solution {
public:
    std::vector<int> shortestAlternatingPaths(int n, std::vector<std::vector<int>>& redEdges, std::vector<std::vector<int>>& blueEdges)
    {
        std::vector<int> answer(n, -1);

        std::unordered_map<int, std::vector<int>> adj_red;
        std::unordered_map<int, std::vector<int>> adj_blue;

        for (auto& pair : redEdges)
            adj_red[pair[0]].push_back(pair[1]);

        for (auto& pair : blueEdges)
            adj_blue[pair[0]].push_back(pair[1]);


        std::vector<bool> visited_red (n, false);
        std::vector<bool> visited_blue(n, false);

        std::queue<std::vector<int>> queue;
        queue.push({0, 0, 0}); // {node, length, prev_edge_color}

        while (!queue.empty())
        {
            std::vector<int> vec = queue.front();
            queue.pop();

            int node       = vec[0];
            int length     = vec[1];
            int edge_color = vec[2]; // 0 == NEITHER, 1 == RED, 2 == BLUE

            if (answer[node] == -1)
                answer[node] = length;

            if (edge_color != 1) // != RED
            {
                for (auto& neighbor : adj_red[node])
                {
                    if (!visited_red[neighbor])
                    {
                        visited_red[neighbor] = true;
                        queue.push({neighbor, length + 1, 1});
                    }
                }
            }

            if (edge_color != 2) // != BLUE
            {
                for (auto& neighbor : adj_blue[node])
                {
                    if (!visited_blue[neighbor])
                    {
                        visited_blue[neighbor] = true;
                        queue.push({neighbor, length + 1, 2});
                    }
                }
            }
        }

        return answer;
    }
};