class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // nodes with zero incoming edges
        vector<bool> incoming(n, false);
        vector<int> ans;

        for(vector<int> edge : edges){
            incoming[edge[1]] = true;
        }

        for(int i=0; i<n; i++){
            if(incoming[i] == false) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/submissions/1138845036/
