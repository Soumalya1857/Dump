
// good solution
// https://www.youtube.com/watch?v=I3lnDUIzIG4
class Solution {
// WA but solution is vvv close
private:

    void bfs(vector<vector<int>> &adj, vector<bool>&rpTaken, int node, long long &fuel, int seats){
        vector<bool> visited(rpTaken.size(), false);
        queue<pair<int,int>> q; // node, seats

        q.push({node, seats});

        while(!q.empty()){
            pair<int,int> curr = q.front(); q.pop();
            cout << "Current element: " << curr.first << " fuel: " << fuel << endl;

            if(curr.first == 0){
                return;
            }

            visited[curr.first] = true;
            // bool isRpTaken = false;
            if(rpTaken[curr.first]){
                // isRpTaken = true;
            } else if(!rpTaken[curr.first] && curr.second > 0){ // seat left in my car
                // isRpTaken = true;
                rpTaken[curr.first] = true;
                curr.second--;
            } else if(!rpTaken[curr.first] && curr.second == 0){
                // isRpTaken = false;
            }
            fuel++;

            for(int nei : adj[curr.first]){
                if(!visited[nei] && !rpTaken[nei]){
                    q.push({nei, curr.second});
                }
            }

        }
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // dfs with some tweaking
        int N = roads.size()+1;

        vector<bool> visited(N, false);// should be locally
        vector<bool> rpTaken(N, false);
        vector<vector<int>> adj(N);

        for(vector<int> road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        //stack<pair<int,int>> s; // node, seats remaining

        long long fuel = 0;

        // initially start with the edge nodes
        for(int i=1; i<N; i++){
            if(!rpTaken[i] && adj[i].size() == 1){
                bfs(adj, rpTaken, i, fuel, seats);
                cout << "starts with: " << i << endl;
                for(int j=0; j<N; j++){
                    cout << j << ":" << rpTaken[j] << " ";
                }

                cout << "\n++++++++++++ fuel: "<< fuel << " +++++++++++++++\n";
            }
        }

        for(int i=1; i<N; i++){
            if(!rpTaken[i]){
                bfs(adj, rpTaken, i, fuel, seats);
                cout << "boogy starts with: " << i << endl;
                for(int j=0; j<N; j++){
                    cout << j << ":" << rpTaken[j] << " ";
                }

                cout << "\n++++++++++++ fuel: "<< fuel << " +++++++++++++++\n";
            }
        }

        return fuel;
    }
};

// sort it based on distance and the start the bfs
// that would be better

class Solution {

private:

    bool static comparator(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }

    void distance(vector<vector<int>> &adj, vector<int> &dist){

       vector<bool> visited(adj.size(), false);
       dist[0] = 0;

       queue<int> q;
       q.push(0);

       int distance=0;
       while(!q.empty()){
           int size = q.size();
           while(size--){
               int curr = q.front(); q.pop();
               visited[curr] = true;

               dist[curr] = distance;

               for(int nei: adj[curr]){
                   if(!visited[nei]){
                       q.push(nei);
                   }
               }
           }

           distance++;
       }


    }

    void bfs(vector<vector<int>> &adj, vector<bool>&rpTaken, int node, long long &fuel, int seats){
        vector<bool> visited(rpTaken.size(), false);
        queue<pair<int,int>> q; // node, seats

        q.push({node, seats});

        while(!q.empty()){
            pair<int,int> curr = q.front(); q.pop();
            cout << "Current element: " << curr.first << " fuel: " << fuel << endl;

            if(curr.first == 0){
                return;
            }

            visited[curr.first] = true;
            // bool isRpTaken = false;
            if(rpTaken[curr.first]){
                // isRpTaken = true;
            } else if(!rpTaken[curr.first] && curr.second > 0){ // seat left in my car
                // isRpTaken = true;
                rpTaken[curr.first] = true;
                curr.second--;
            } else if(!rpTaken[curr.first] && curr.second == 0){
                // isRpTaken = false;
            }
            fuel++;

            for(int nei : adj[curr.first]){
                if(!visited[nei] && !rpTaken[nei]){
                    q.push({nei, curr.second});
                }
            }

        }
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // dfs with some tweaking
        int N = roads.size()+1;

        vector<bool> visited(N, false);// should be locally
        vector<bool> rpTaken(N, false);
        vector<vector<int>> adj(N);

        for(vector<int> road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        vector<int> dist(N, 1000000);
        distance(adj, dist);

        vector<pair<int,int>> distance; // node, distance
        for(int i=0; i<N; i++){
            distance.push_back({i,dist[i]});
        }

        sort(distance.begin(), distance.end(), comparator);

        long long fuel = 0;

        for(pair<int,int> entry : distance){
            int node = entry.first;
            if(!rpTaken[node]){
                bfs(adj, rpTaken, node, fuel, seats);
                cout << "starts with: " << node << endl;
                for(int j=0; j<N; j++){
                    cout << j << ":" << rpTaken[j] << " ";
                }

                cout << "\n++++++++++++ fuel: "<< fuel << " +++++++++++++++\n";
            }
        }

        // initially start with the edge nodes
        // for(int i=1; i<N; i++){
        //     if(!rpTaken[i] && adj[i].size() == 1){
        //         bfs(adj, rpTaken, i, fuel, seats);
        //         cout << "starts with: " << i << endl;
        //         for(int j=0; j<N; j++){
        //             cout << j << ":" << rpTaken[j] << " ";
        //         }

        //         cout << "\n++++++++++++ fuel: "<< fuel << " +++++++++++++++\n";
        //     }
        // }

        // for(int i=1; i<N; i++){
        //     if(!rpTaken[i]){
        //         bfs(adj, rpTaken, i, fuel, seats);
        //         cout << "boogy starts with: " << i << endl;
        //         for(int j=0; j<N; j++){
        //             cout << j << ":" << rpTaken[j] << " ";
        //         }

        //         cout << "\n++++++++++++ fuel: "<< fuel << " +++++++++++++++\n";
        //     }
        // }

        return fuel;
    }
};


// still getting WA

// this is a good problem
// correct approach would be learing that calculate cars to take people to there parent
// that is ceil(totalChildren/seats)

class Solution {
public:
    // updates fuel and return total number of child to parent
    int dfs(vector<vector<int>>& adj, long long &fuel, int seats, int node, int parent){
        int children = 0;

        for(int child : adj[node]){
            if(child != parent){
                int c = dfs(adj, fuel, seats, child, node);
                children += c;
                fuel += (int)ceil((double)c/seats);
            }
        }

        return 1+children;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int N = roads.size() + 1;

        vector<vector<int>> adj(N);

        for(vector<int> road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        // start dfs from 0
        long long fuel = 0;
        dfs(adj, fuel, seats, 0, -1);
        return fuel;
    }
};

// https://www.youtube.com/watch?v=I3lnDUIzIG4