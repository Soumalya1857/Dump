class Solution {
public:

    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(NULL);
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> adj(n);
        for(int i=0; i<manager.size(); i++){
            if(i==headID) continue;

            adj[manager[i]].push_back(i);
        }


        // dfs
        stack<pair<int,int>> q; // employee, time
        q.push({headID, 0});

        int maxTime = -1;

        while(!q.empty()){
            int currEmp = q.top().first;
            int currTime = q.top().second;

            q.pop();

            maxTime = max(maxTime, currTime);

            for(int sub : adj[currEmp]){
                q.push({sub, currTime + informTime[currEmp]});
            }
        }

        return maxTime;
    }
};

// https://leetcode.com/problems/time-needed-to-inform-all-employees/