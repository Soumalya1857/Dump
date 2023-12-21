class Solution {
public:

    // direct application of toposort
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for(vector<int> pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> topo;

        vector<int> indegree(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            for(int nei : adj[i]){
                indegree[nei]++;
            }
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int element = q.front(); q.pop();

            topo.push_back(element);

            for(int nei : adj[element]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }

        // for loop in the system
        for(int deg : indegree){
            if(deg != 0) return vector<int>();
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};

// https://leetcode.com/problems/course-schedule-ii/
// solution: kahn's algorithm
// https://www.youtube.com/watch?v=73sneFXuTEg&t=1s