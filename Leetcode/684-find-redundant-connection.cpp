class Solution {

private:

    int parent[1005], rank[1005];

    // 5 --> 4 --> 3 --> 2 --> 1
    int getParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = getParent(parent[node]);
    }


    void unionFind(int u, int v){
        int uRoot = getParent(u);
        int vRoot = getParent(v);

        if(rank[uRoot] > rank[vRoot]){
            parent[vRoot] = uRoot;
        } else if(rank[vRoot] > rank[uRoot]){
            parent[uRoot] = vRoot;
        } else if(rank[uRoot] == rank[vRoot]){
            parent[vRoot] = uRoot;
            rank[uRoot]+=1;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // unordered_map<int,bool> visited;
        // vector<vector<int>> adj(1002, vector<int>());

        // int startNode = INT_MAX;

        // for(vector<int> edge : edges){
        //     startNode = min(edge[1], min(startNode, edge[0]));
        //     adj[edge[0]].push_back(edge[1]);
        //     adj[edge[1]].push_back(edge[0]);
        // }

        // stack<pair<int,int>> s; // curr, parent
        // s.push({startNode, -1});

        // while(!s.empty()){
        //     pair<int,int> curr = s.top(); s.pop();

        //     if(visited[curr.first]){
        //         return vector<int>{curr.first, curr.second};
        //     }

        //     visited[curr.first] = true;
        //     for(int nei : adj[curr.first]){
        //         if(!visited[nei]){
        //             s.push({nei, curr.first});
        //         }
        //     }
        // }


        // return vector<int>{-1,-1};


        // min spanning tree
        // build the tree as you go for it
        // disjoint set union bro
        // where if got a edge who connect same parent wala nodes, or connect child with parent directly
        // that's a loop edge bro


        for(int i=0; i<1005; i++) {
            parent[i] = i;
            rank[i] = 0;
        }


        for(vector<int> edge : edges){
            int uParent = getParent(edge[0]), vParent = getParent(edge[1]);

            if(uParent == vParent){
                return edge;
            }

            unionFind(edge[0], edge[1]);
        }

        return vector<int>{-1,-1};

    }
};

// disjoint set union (DSU dsu)
// https://leetcode.com/problems/redundant-connection/