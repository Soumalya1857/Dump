
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