class Solution {
public:
    // same problem 
    // topo sort and dfs 
    // cycle detected....those courses cannot be done


    // not a working code --- TLE

    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int currIndex ){
        stack<pair<int, vector<bool>>> s;
        vector<bool> localPath(adj.size(), false);
        s.push({currIndex, localPath});
        //cout << "start: " << currIndex << endl;

        while(!s.empty()){
            pair<int, vector<bool>> currElement = s.top();
            s.pop();

            int curr = currElement.first;
            vector<bool> localPath = currElement.second;

            if(localPath[curr]){
                //cout << "a curr: " << curr << endl;
                return false; // cycle present
            } 

            localPath[curr] = true;
            visited[curr] = true;

            for(int i=0; i<adj[curr].size(); i++){
                int nei = adj[curr][i];
                //cout << "curr: " << curr << " nei: " << nei << " localPath: " << localPath[nei] << endl;
                
                if(!localPath[nei]){
                    // vector<bool> copyLocal;
                    // copyLocal = localPath;
                    // s.push({nei, copyLocal});

                    s.push({nei, localPath}); // copy by value here
                }else if(localPath[nei]){
                    //cout << "b curr: " << curr << endl;
                    return false;
                }
                
            }
        }

        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for(vector<int> entry : prerequisites){
            adj[entry[0]].push_back(entry[1]);
        }

        vector<bool> visited(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(adj, visited, i) == false){
                    return false;
                }
            }
        }

        return true;
    }
};







/// https://leetcode.com/problems/course-schedule/

class Solution {

private:
    bool isCyclic(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited, int curr){
        
        visited[curr] = true;
        pathVisited[curr] = true;

        for(int nei : adj[curr]){
            if(!visited[nei]){
               if( isCyclic(adj, visited, pathVisited, nei)){
                   return true;
               }
            }else if(pathVisited[nei]){
                return true;
            }
        }


        // backtrack
        pathVisited[curr] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        vector<vector<int>> adj(numCourses, vector<int>());

        for(vector<int> entry : prerequisites){
            adj[entry[0]].push_back(entry[1]);
        }

        for(int index = 0; index < numCourses; index++){
            if(!visited[index]){
                if(isCyclic(adj, visited, pathVisited, index)){
                    return false;
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/course-schedule/
// solution ; https://www.youtube.com/watch?v=9twcmtQj4DU


// bitset implementation
class Solution {

private:
    bitset<2001> visited, pathVisited;

    bool isCyclic(vector<vector<int>> &adj, int curr){
        
        visited.set(curr);
        pathVisited.set(curr);

        for(int nei : adj[curr]){
            if(!visited.test(nei)){
               if( isCyclic(adj, nei)){
                   return true;
               }
            }else if(pathVisited.test(nei)){
                return true;
            }
        }

        // backtrack
        pathVisited.reset(curr);
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // vector<bool> visited(numCourses, false);
        // vector<bool> pathVisited(numCourses, false);

        //bitset<numCourses> visited, pathVisited;

        vector<vector<int>> adj(numCourses, vector<int>());

        for(vector<int> entry : prerequisites){
            adj[entry[0]].push_back(entry[1]);
        }

        for(int index = 0; index < numCourses; index++){
            if(!visited.test(index)){
                if(isCyclic(adj, index)){
                    return false;
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/course-schedule/
// solution ; https://www.youtube.com/watch?v=9twcmtQj4DU



// khan's algorithm

