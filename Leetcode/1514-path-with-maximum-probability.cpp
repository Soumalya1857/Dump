/*
I am surprised to see such a long editorial (three different algorithms with a lot of what sounds like chat GPT generated explanations of the code and a plethora of diagrams) that at no point attempts to justify why using these algorithms give the correct answer for the problem.

"We need to find the path from start to end that has the largest product of its edges" - fine

"BFS is an algorithm I know but it's not used on graphs with weighted edges, let's use Dijkstra instead because that one works on weighted graphs" - cool story bro, but Dijkstra is a shortest path algorithm, not a largest product algorithm...

For anyone who is curious why it works and hasn't worked it out themselves:

Call product of the edges in a path P = p1 * ... * pk
We want to find the path with maximum P.
Since the logarithm is a monotonically growing function, the path with largest P is also the path with largest log(P), (and the smallest -log(P))
due to the properties of the logarithm, log(P) = log(p1) + ... + log(pk)
if we take the negative -log(P) = -log(p1) + (-log(p2)) + ... + (-log(pk))
In summary: maximizing P (the problem) is equivalent to minimizing -log(P) which is just the sum of the negative logarithms of the edge weights. This equivalent modified problem IS a shortest path problem
Furthermore, since 0 <= pi <= 1, that means log(pi) <= 0 and -log(pi) >= 0. Non-negative edges, a requirement for Dijkstra to work properly.
So yeah, TL;DR: "weighted graph, can't be BFS, let's use Dijkstra" is dumb, but since edge weights are probabilities, finding the maximum product is equivalent to a shortest path problem with non-negative edge weights, and Dijkstra "just works"


The word 'shorter' in shortest path algorithms simply means 'easier/best/optimal'. To see why this is a shortest path algorithm, consider the statement in the problem description 'succProb[i] is the probability of success when attempting to traverse an edge'. If an edge is labeled with a higher probability, then it is 'easier' to traverse that path i.e you have higher chances of success in traversing that edge.
Hence, a path that generates the highest probability will be the shortest path because it has higher chances of successful traversal more than any of the other lower probability (harder to traverse) paths.

*/


// dijktra might work here
// priority queue here is actually slower
// don't know why

class Solution {
private:
struct Node{
    int node;
    // int parent;
    double prob;

    Node(int node/*, int parent*/, double prob): node(node)/*, parent(parent)*/, prob(prob) {}
};


public:
static bool comparator(const Node &a, const Node &b){
    return a.prob > b.prob;

}
struct MyComp {
    constexpr bool operator()(
        Node const& a,
        Node const& b)
        const noexcept
    {
        return a.prob > b.prob;
    }
};
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n+1);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        //priority_queue<Node, vector<Node>, MyComp> pq;
        vector<double> prob(n+1,0.0);
        queue<Node> pq;

        Node temp(start_node, 1);
        pq.push(temp);

        double maxProb = 0;
        while(!pq.empty()){
            Node curr = pq.front(); pq.pop();

            prob[curr.node] = max(curr.prob, prob[curr.node]);
            if(curr.node == end_node){
                maxProb = max(maxProb, curr.prob);
                continue;
            }

            for(pair<int, double> nei : adj[curr.node]){
                if(prob[nei.first] < prob[curr.node] * nei.second){
                    pq.push({nei.first, prob[curr.node] * nei.second});
                }
            }
        }

        return maxProb;

        // while(!pq.empty()){
        //     Node curr = pq.front();
        //     pq.pop();

        //     if(curr.node == end_node){
        //         maxProb = max(maxProb, curr.prob);
        //         continue;
        //     }

        //     for(pair<int,double> nei : adj[curr.node]){
        //         if(nei.first != curr.parent){
        //             Node temp(nei.first, curr.node, curr.prob * nei.second);
        //             pq.push(temp);
        //         }
        //     }
        // }

        return maxProb;

    }
};

// short circuit with priority queue
class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
        vector<double>dis(n,0);
        priority_queue<pair<double,int>>pq;
        dis[start_node]=1;
        pq.push({1,start_node});
        while(!pq.empty())
        {
            double prob=pq.top().first;
            int curr=pq.top().second;
            pq.pop();
            if(curr==end_node)
            {
                return dis[curr];
            }
            for(auto nxt:adj[curr])
            {
                double prob=nxt.second;
                int node=nxt.first;
                if(dis[node]<dis[curr]*prob)
                {
                    dis[node]=dis[curr]*prob;
                    pq.push({dis[node],node});
                }

            }

        }
        return 0;




    }
};