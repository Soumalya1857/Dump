// https://leetcode.com/problems/number-of-good-paths/description/

//Got MLE with this
class Solution {

private:

bool isGoodPath(vector<vector<int>> &adj, vector<int> &vals, int start, int end){
    if(vals[start] != vals[end]) return false;
    if(start == end) return true;

    stack<pair<int,int>> s; // index curr node, maxTillNow
    s.push({start, vals[start]});

    vector<bool> visited(vals.size(), false);

    while(!s.empty()){
        pair<int,int> curr = s.top(); s.pop();
        if(start == 1 || start == 4){
            // cout << "node: " << curr.first;
            // cout << "max: " << curr.second;
        }
        visited[curr.first] = true;
        if(curr.first == end){
            if(curr.second <= vals[start]){
                return true;
            }

            continue;
        }

        for(int nei : adj[curr.first]){
            if(!visited[nei]){
                s.push({nei, max(vals[nei], curr.second)});
            }
        }
    }

    return false;
}
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = vals.size();
        // 2d array addition
        map<int,vector<int>> freq; // val => vector of index

        for(int i=0; i<vals.size(); i++){
            freq[vals[i]].push_back(i);
        }

        // for(auto entry : freq){
        //     cout << entry.first << endl;
        //     for(int x : entry.second) cout << x << " ";
        //     cout << endl;
        // }

        vector<vector<int>> adj(vals.size());

        for(int i=0; i<edges.size(); i++){
            //cout << edges[i][0] <<"-" << edges[i][1] << "\n";
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        for(auto entry : freq){
            //cout << entry.second.size()<< "boobies\n";
            if(entry.second.size() > 1){
                int size = entry.second.size();
                for(int i=0; i<size; i++){
                    for(int j=i+1; j<size; j++){
                        //if(entry.first == 1) cout << i << " " << j << "<= hehe" << endl;
                        if(isGoodPath(adj, vals, entry.second[i], entry.second[j])){
                            ans++;
                        }
                    }
                }
            }
        }



        return ans;
    }
};

// solution can be done with DSU
// disjoint set union
// but seemed forced solution



