// verdict: Accepted
// but very bad runtime
class Solution {
private:
    int dfs(vector<vector<int>> &adj, int node, vector<bool> &visited){
        stack<int> s;
        s.push(node);
        int count = 0;


        while(!s.empty()){
            int currNode = s.top(); s.pop();

            if(!visited[currNode]){
                count++;
            }

            visited[currNode] = true;

            for(int nei : adj[currNode]){
                if(!visited[nei]){
                    s.push(nei);
                }
            }
        }

        return count;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int> countIslands;
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);


        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<adj.size(); i++){
            int count = 0;
            if(!visited[i]){
                count = dfs(adj, i, visited);
                //cout << "count: " << count << " i: " << i << endl;
            }

            countIslands.push_back(count);
        }

        long long ans = 0;
        long long runningCount = 0;

        /*
         given a,b,c,d
         need ab+bc+ca+da+bd+cd

         => a*b
         + (a+b)*c
         + (a+b+c)*d
        */

        for(int i=0; i<countIslands.size(); i++){
            ans += (runningCount * countIslands[i]);
            runningCount += countIslands[i];
        }

        return ans;
    }
};

// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
// BUT IT"S A GREAT QUESTION FOR UNION FIND

class DSU{
    private:
        int n;
        vector<int> rank;
        vector<int> parent;

    public:
        DSU(int n){
            this->n = n;
            this->rank = vector<int>(n,0);
            this->parent = vector<int>(n);

            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int findParent(int u){
            if(u == parent[u]){
                return u;
            }

            return parent[u] = findParent(parent[u]);
        }

        void makeUnion(int u, int v){
            u = findParent(u);
            v = findParent(v);

            if(rank[u] > rank[v]){
                parent[v] = u;
            } else if(rank[v] > rank[u]){
                parent[u] = v;
            }else{ // rank[u] == rank[v]
                parent[v] = u;
                rank[u]++;
            }
        }

        vector<int> getFrequency(){
            unordered_map<int,int> mp; // node => freq
            for(int i=0; i<n; i++){
                parent[i] = findParent(i); // this is vvv important as some of the node might not have updated parent
                mp[parent[i]]++;

                //cout << "node: " << i << " parent: " << parent[i] << endl;
            }

            vector<int> freq;
            for(auto entry : mp){
                freq.push_back(entry.second);
            }

            return freq;
        }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(vector<int> edge: edges){
            dsu.makeUnion(edge[0], edge[1]);
        }

        vector<int> freq = dsu.getFrequency();

        // cout << "=========================\n";
        // for(int a : freq){
        //     cout << a << " ";
        // }
        // cout << endl;

        long long ans = 0, runningSum = 0;

        for(int i=0; i<freq.size(); i++){
            ans += (runningSum * freq[i]);
            runningSum += freq[i];
        }

        return ans;
    }
};

