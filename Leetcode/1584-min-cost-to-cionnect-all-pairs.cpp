// krusgal algorithm

class Solution {
private:

int abso(int n){
    return n<0 ? -n : n;
}

struct Edge{
    int x1,x2,y1,y2;
    int dist;

    Edge(int x1, int x2, int y1, int y2, int dist): x1(x1), x2(x2), y1(y1), y2(y2), dist(dist) {}
};

static bool comparator(const Edge &a, const Edge &b){
    return a.dist < b.dist;
}

bool isSame(pair<int,int> a, pair<int,int> b){
    return a.first == b.first && a.second == b.second;
}

bool dfs(map<pair<int,int> , vector<pair<int,int>>> &adj){
    map<pair<int,int>, bool> visited;

    for(auto &entry : adj){
        if(!visited[entry.first]){
            stack<pair<pair<int,int>, pair<int,int>>> s; // curr, parent
            s.push({entry.first, {1e9,1e9}});

            while(!s.empty()){
                auto curr = s.top(); s.pop();

                visited[curr.first] = true;

                for(pair<int,int> nei : adj[curr.first]){
                    if(visited[nei] && !isSame(nei, curr.second)){
                        return true;
                    }

                    if(!visited[nei] && !isSame(nei, curr.second)){ // should not the
                        s.push({nei, curr.first}); // neighbor, me
                    }
                }
            }
        }
    }

    return false;
}

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // krusgal algo
        // sort all the edges for weight, take out the min weight see if that forms any cycle or not

        // total nc2 edges

        int totalPoints = points.size(), edgeReq = totalPoints-1, ans = 0;

        vector<Edge> edges;
        for(int i=0; i<totalPoints; i++){
            for(int j=i+1; j<totalPoints; j++){
                int dist = abso(points[i][0]-points[j][0]) + abso(points[i][1] - points[j][1]);
                Edge temp(points[i][0], points[j][0], points[i][1], points[j][1], dist);

                edges.push_back(temp);
            }
        }

        sort(edges.begin(), edges.end(), comparator);

        map<pair<int,int> , vector<pair<int,int>>> adj;
        int edgeAddedTillNow = 0;

        for(int i=0; i<edges.size(); i++){
            adj[{edges[i].x1, edges[i].y1}].push_back({edges[i].x2, edges[i].y2});
            adj[{edges[i].x2, edges[i].y2}].push_back({edges[i].x1, edges[i].y1});

            bool isCycleDetected = dfs(adj);
           //cout << "isCycle: " << isCycleDetected << " i:" << i << endl;

            if(isCycleDetected){ // rollback
                adj[{edges[i].x1, edges[i].y1}].pop_back();
                adj[{edges[i].x2, edges[i].y2}].pop_back();
            }else{
                ans += edges[i].dist;
                edgeAddedTillNow += 1;
                //cout << "i: " << "edge: " << edgeAddedTillNow << endl;
            }

            if(edgeAddedTillNow == edgeReq){
                return ans;
            }
        }

        return 0;

    }
};

// https://leetcode.com/problems/min-cost-to-connect-all-points/

// better solution is to detect cycle with DSU
class Solution {
private:

map<pair<int,int>, int> rank;
map<pair<int,int> , pair<int,int>> parent;

int abso(int n){
    return n<0 ? -n : n;
}

struct Edge{
    int x1,x2,y1,y2;
    int dist;

    Edge(int x1, int x2, int y1, int y2, int dist): x1(x1), x2(x2), y1(y1), y2(y2), dist(dist) {}
};

static bool comparator(const Edge &a, const Edge &b){
    return a.dist < b.dist;
}

bool isSame(pair<int,int> a, pair<int,int> b){
    return a.first == b.first && a.second == b.second;
}

bool dfs(map<pair<int,int> , vector<pair<int,int>>> &adj){
    map<pair<int,int>, bool> visited;

    for(auto &entry : adj){
        if(!visited[entry.first]){
            stack<pair<pair<int,int>, pair<int,int>>> s; // curr, parent
            s.push({entry.first, {1e9,1e9}});

            while(!s.empty()){
                auto curr = s.top(); s.pop();

                visited[curr.first] = true;

                for(pair<int,int> nei : adj[curr.first]){
                    if(visited[nei] && !isSame(nei, curr.second)){
                        return true;
                    }

                    if(!visited[nei] && !isSame(nei, curr.second)){ // should not the
                        s.push({nei, curr.first}); // neighbor, me
                    }
                }
            }
        }
    }

    return false;
}

pair<int,int> getParent(pair<int,int> a){
    if(isSame(a, parent[a])){
        return a;
    }

    return parent[a] = getParent(parent[a]);
}

void makeUnion(pair<int,int> a, pair<int,int> b){
    a = getParent(a);
    b = getParent(b);

    if(rank[a] > rank[b]){
        parent[b] = a;
    } else if(rank[b] > rank[a]){
        parent[a] = b;
    } else {
        parent[b] = a;
        rank[a]++;
    }
}


// bool dsu(map<pair<int,int> , vector<pair<int,int>>> &adj){ // to detect the cycle we can also use dsu

// }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // krusgal algo
        // sort all the edges for weight, take out the min weight see if that forms any cycle or not

        // total nc2 edges

        int totalPoints = points.size(), edgeReq = totalPoints-1, ans = 0;

        vector<Edge> edges;
        for(int i=0; i<totalPoints; i++){
            // initialize the dsu
            pair<int,int> point = {points[i][0], points[i][1]};
            parent[point] = point;
            rank[point] = 0;

            for(int j=i+1; j<totalPoints; j++){
                int dist = abso(points[i][0]-points[j][0]) + abso(points[i][1] - points[j][1]);
                Edge temp(points[i][0], points[j][0], points[i][1], points[j][1], dist);

                edges.push_back(temp);
            }
        }

        sort(edges.begin(), edges.end(), comparator);

        map<pair<int,int> , vector<pair<int,int>>> adj;
        int edgeAddedTillNow = 0;

        for(int i=0; i<edges.size(); i++){
            adj[{edges[i].x1, edges[i].y1}].push_back({edges[i].x2, edges[i].y2});
            adj[{edges[i].x2, edges[i].y2}].push_back({edges[i].x1, edges[i].y1});

            // bool isCycleDetected = dfs(adj);
           //cout << "isCycle: " << isCycleDetected << " i:" << i << endl;

            bool isCycleDetected = (getParent({edges[i].x1, edges[i].y1}) == getParent({edges[i].x2, edges[i].y2}));

            if(isCycleDetected){ // rollback
                adj[{edges[i].x1, edges[i].y1}].pop_back();
                adj[{edges[i].x2, edges[i].y2}].pop_back();
            }else{
                makeUnion({edges[i].x1, edges[i].y1}, {edges[i].x2, edges[i].y2} );
                ans += edges[i].dist;
                edgeAddedTillNow += 1;
                //cout << "i: " << "edge: " << edgeAddedTillNow << endl;
            }

            if(edgeAddedTillNow == edgeReq){
                return ans;
            }
        }

        return 0;
    }
};





































