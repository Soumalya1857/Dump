
// wrong solution based on disjoint set union
class Solution {
private:
    int rank[102], parent[102];

    int getParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = getParent(parent[node]);
    }

    void makeUnion(int u, int v){
        u = getParent(u);
        v = getParent(v);

        if(rank[u] > rank[v]){
            parent[v] = u;
            rank[u]++;
        } else if(rank[v] > rank[u]){
            parent[u] = v;
            rank[v]++;
        } else {// 0,1 means 1-->0
            parent[v] = u;
            rank[u]+=rank[v];
        }
    }

    void makeSet(){
        for(int i=0; i<102; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        makeSet();

        vector<bool> ans;
        for(vector<int> pre : prerequisites){
            makeUnion(pre[0], pre[1]);
        }

        for(vector<int> query : queries){
            if(getParent(query[0]) == getParent(query[1])){ // q1 should comes 1st ---> q0
                ans.push_back(rank[query[0]] >= rank[query[1]]);
            } else{
                ans.push_back(false);
            }

        }

        return ans;
    }
};

// https://leetcode.com/problems/course-schedule-iv/
/*=============================================================================*/
// use standard topo sort

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);

        for(vector<int> pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }

        queue<int> q; // why??
        for(int i=0; i<numCourses;i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }

        int index = 0;
        unordered_map<int, int> mp; // val, index

        while(!q.empty()){
            int curr = q.front(); q.pop();

            mp[curr] = numCourses-1-index; // visited and marked
            index++;

            for(int nei : adj[curr]){
                indegrees[nei]--;
                if(indegrees[nei] == 0)
                    q.push(nei);
            }

        }

        vector<bool> ans;

        for(vector<int> que : queries){
            ans.push_back(mp[que[0]] < mp[que[1]]);
        }

        return ans;
    }
};

// still WA for some test cases


// neetcode
// Accepted multiple DFS to mark the path
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);

        for(vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
            // indegrees[pre[0]]++;
        }

        vector<vector<bool>> visited(numCourses, vector<bool>(numCourses, false));

        stack<int> q;

        for(int i=0; i<numCourses; i++){
            q.push(i);
            while(!q.empty()){
                int curr = q.top(); q.pop();

                if(visited[i][curr]) continue;

                visited[i][curr] = true;

                for(int nei: adj[curr]){
                    if(!visited[i][nei]){
                        q.push(nei);
                    }
                }
            }
        }

        vector<bool> ans;
        for(vector<int> query : queries){
            ans.push_back(visited[query[0]][query[1]]);
        }

        return ans;

        // queue<int> q;
        // for(int i=0; i<numCourses;i++){
        //     if(indegrees[i] == 0){
        //         q.push(i);
        //     }
        // }

        // int index = 0;
        // unordered_map<int, int> mp; // val, index

        // while(!q.empty()){
        //     int curr = q.front(); q.pop();

        //     mp[curr] = numCourses-1-index; // visited and marked
        //     index++;

        //     for(int nei : adj[curr]){
        //         indegrees[nei]--;
        //         if(indegrees[nei] == 0)
        //             q.push(nei);
        //     }

        // }

        // vector<bool> ans;

        // for(vector<int> que : queries){
        //     ans.push_back(mp[que[0]] < mp[que[1]]);
        // }

        return ans;
    }
};