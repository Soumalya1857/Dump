// very bad code not efficient at all

class Solution {
private:
struct Node{
    string curr;
    vector<string> path;
    map<pair<string,string>, bool> mp;
    int ticketRemaining;

    Node(string curr, vector<string> path, map<pair<string,string>,bool> mp, int ticketRemaining):
        curr(curr),
        path(path),
        mp(mp),
        ticketRemaining(ticketRemaining){}


    // Node(Node &a){
    //     this->curr = a.curr;
    //     this->path = a.path;
    //     this->mp = a.mp;
    //     this->ticketRemaining = a.ticketRemaining;
    // }
};


public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //priority_queue<string, vector<string>, greater<string>> pq;

        map<string, vector<string>> adj;
        for(vector<string> ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto &entry : adj){
            sort(entry.second.begin(), entry.second.end());
        }
        vector<string> path;
        path.push_back("JFK");
        map<pair<string,string>, bool> mp;

        stack<Node> s;
        s.push(Node("JFK", path, mp, tickets.size()));

        while(!s.empty()){
            Node currNode = s.top(); s.pop();

            cout << currNode.curr << " " << currNode.ticketRemaining << endl;
            //currNode.path.push_back(currNode.curr);

            if(currNode.ticketRemaining == 0){
                return currNode.path;
            }

            //priority_queue<string, vector<string>, greater<string>> pq;
            for(string nei : adj[currNode.curr]){
                if(!currNode.mp[{currNode.curr, nei}]){
                    currNode.mp[{currNode.curr, nei}] = true;
                    vector<string> path(currNode.path);
                    map<pair<string,string>, bool> tempMP(mp);
                    path.push_back(nei);
                    int ticketsNow = currNode.ticketRemaining-1;
                    s.push({nei,path, tempMP, ticketsNow});
                }
            }
        }
        vector<string> ans;
        cout << "Boo" << endl;
        return ans;
    }
};
// https://leetcode.com/problems/reconstruct-itinerary/
// a good solution is based on good use of a recursive DFS
// https://leetcode.com/problems/reconstruct-itinerary/solutions/78766/share-my-solution

// read the comments for better understanding
/*All the airports are vertices and tickets are directed edges. Then all these tickets form a directed graph.

  The graph must be Eulerian since we know that a Eulerian path exists.

  Thus, start from "JFK", we can apply the Hierholzer's algorithm to find a Eulerian path in the graph which is a valid reconstruction.

  Since the problem asks for lexical order smallest solution, we can put the neighbors in a min-heap. In this way, we always visit the smallest possible neighbor first in our trip.*/


public class Solution {

    Map<String, PriorityQueue<String>> flights;
    LinkedList<String> path;

    public List<String> findItinerary(String[][] tickets) {
        flights = new HashMap<>();
        path = new LinkedList<>();
        for (String[] ticket : tickets) {
            flights.putIfAbsent(ticket[0], new PriorityQueue<>());
            flights.get(ticket[0]).add(ticket[1]);
        }
        dfs("JFK");
        return path;
    }

    public void dfs(String departure) {
        PriorityQueue<String> arrivals = flights.get(departure);
        while (arrivals != null && !arrivals.isEmpty())
            dfs(arrivals.poll());
        path.addFirst(departure);
    }
}

79 / 79 test cases passed.
Status: Accepted
Runtime: 11 ms
