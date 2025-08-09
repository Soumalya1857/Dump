
// good problem boss
class Solution {

private:
    struct Node{
        string first;
        //string second;
        double val;
    };

    double bfs(map<string,vector<string>> &adj, string start, string destination, map<pair<string, string>, double> eqs){
        Node node;
        node.first = start;
        node.val = 1.0;
        unordered_map<string, bool> visited;


        queue<Node> q;
        q.push(node);

        while(!q.empty()){
            Node curr = q.front(); q.pop();

            visited[curr.first] = true;
            if(curr.first == destination){
                return curr.val;
            }

            for(string nei : adj[curr.first]){
                if(!visited[nei]){
                    Node temp;
                    temp.first = nei;
                    temp.val = curr.val * eqs[{curr.first, nei}];

                    q.push(temp);
                }
            }


        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // a/b is also means b/a exists
        vector<double> ans;
        map<pair<string, string>, double> eqs;
        for(int i=0; i<equations.size(); i++){
            eqs.insert({{equations[i][0], equations[i][1]}, values[i]});
            eqs.insert({{equations[i][1], equations[i][0]}, (double)1.0/values[i]});
        }

        map<string,vector<string>> adj;
        for(vector<string> eq : equations){
            adj[eq[0]].push_back(eq[1]);
            adj[eq[1]].push_back(eq[0]);
        }

        for(vector<string> query : queries){
            if(adj.find(query[0]) == adj.end() || adj.find(query[1]) == adj.end() ){
                ans.push_back(-1.0);
                continue;
            }

            // else condition
            // do a bfs => shortest path

            double val = bfs(adj, query[0], query[1], eqs);
            ans.push_back(val);
        }

        return ans;
    }
};

// https://leetcode.com/problems/evaluate-division/submissions/1139509682/