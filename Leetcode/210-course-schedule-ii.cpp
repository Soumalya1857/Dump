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


// ==============================================
// DFS approach => insert in a stack

// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

//     }
// };

class Solution {

private:
    bitset<2001> visited, pathVisited;

    bool isCyclic(vector<vector<int>> &adj, int curr, stack<int> &s){

        visited.set(curr);
        pathVisited.set(curr);

        for(int nei : adj[curr]){
            if(!visited.test(nei)){
               if( isCyclic(adj, nei, s)){
                   return true;
               }
            }else if(pathVisited.test(nei)){
                return true; // cycle detected boss
            }
        }

        // backtrack
        // s.push(curr);
        s.push(curr);
        pathVisited.reset(curr);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // vector<bool> visited(numCourses, false);
        // vector<bool> pathVisited(numCourses, false);

        //bitset<numCourses> visited, pathVisited;

        vector<vector<int>> adj(numCourses, vector<int>());
        stack<int> courses;

        for(vector<int> entry : prerequisites){
            adj[entry[1]].push_back(entry[0]);
        }

        for(int index = 0; index < numCourses; index++){
            if(!visited.test(index)){
                if(isCyclic(adj, index, courses)==true){
                    return vector<int>();
                }
            }
        }

        vector<int> ans;
        while(!courses.empty()){
            ans.push_back(courses.top());
            courses.pop();
        }

        return ans;
    }
};

// https://leetcode.com/problems/course-schedule/
// solution ; https://www.youtube.com/watch?v=9twcmtQj4DU

// ========================= if the question is how many permutations are possible
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

        vector<int> occurs;

        while(!q.empty()){

            int size = q.size();
            occurs.push_back(size);

            while(size--){ // if the question states how many valid permutations are possible!!!!!
                int element = q.front(); q.pop();
                topo.push_back(element);
                for(int nei: adj[element]){
                    indegree[nei]--;
                    if(indegree[nei] == 0){
                        q.push(nei);
                    }
                }
            }

            // topo.push_back(element);

            // for(int nei : adj[element]){
            //     indegree[nei]--;
            //     if(indegree[nei] == 0) q.push(nei);
            // }
        }

        for(int occur : occurs){
            cout << occur << " ";
        }
        cout << endl;

        for(int deg : indegree){
            if(deg != 0) return vector<int>();
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};