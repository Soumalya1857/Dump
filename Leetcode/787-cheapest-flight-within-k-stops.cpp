class Solution {
    private:
    struct Node{
        int node;
        int price;
        int steps;

        Node(int node, int price, int steps): node(node), price(price), steps(steps){}
    };
    public:
    class MyComp{
        public:
        bool operator()(const Node &a, const Node &b){
            return a.price > b.price; // ascending order on price
        }
    };
    // dijktra's with k check
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n); // {dest, price}
        vector<int> dist(n, 1e9);

        for(vector<int> flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // curr, price, steps
        //priority_queue<Node, vector<Node>, MyComp> pq;
        queue<Node> pq;
        pq.push(Node(src,0,0));
        dist[src] = 0;
        //pq.push(Node(src, 0, 0));

        int minPrice = 1e9;

        while(!pq.empty()){
            Node curr = pq.front(); pq.pop();
            if(curr.steps <= k+1){
                dist[curr.node] = min(dist[curr.node], curr.price);
            }

            if(curr.node == dst && curr.steps <= k+1){ // number of stops, not edges thus k+1
                minPrice = min(minPrice, dist[curr.node]);
                // for(int x : dist) cout << x << " ";
                // cout << endl;
                continue;
            }

            for(pair<int,int> nei : adj[curr.node]){
                if(dist[nei.first] > curr.price + nei.second){
                    if(curr.steps + 1 <= k+1){
                        pq.push(Node(nei.first, curr.price + nei.second, curr.steps + 1));
                    }
                }
            }
        }

        return  minPrice == 1e9 ? -1 : minPrice;
    }
};

// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/