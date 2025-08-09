class Solution {
public:
    int minJumps(vector<int>& arr) {
        // bfs strategy again with count of steps

        unordered_map<int, vector<int>> map;

        for(int i = 0; i<arr.size(); i++){
            map[arr[i]].push_back(i);
        }

        vector<bool> isVisited(arr.size(), false);
        queue<int> q; // index
        int steps = 0;

        q.push(0);

        while(!q.empty()){
            int queueSize = q.size();
            while(queueSize--){
                int currIndex = q.front();
                q.pop();

                if(currIndex == arr.size()-1) return steps;
                isVisited[currIndex] = true;

                if(currIndex + 1 < arr.size() && !isVisited[currIndex + 1])
                    q.push(currIndex+1);

                if(currIndex-1>=0 && !isVisited[currIndex-1])
                    q.push(currIndex-1);

                vector<int> similarIndex = map[arr[currIndex]];
                for(int index : similarIndex){
                    if(!isVisited[index] && currIndex != index)
                        q.push(index);
                }

                map.erase(arr[currIndex]); // to delete memory from map
            }

            steps++;
        }

        return -1;

    }
};

// https://leetcode.com/problems/jump-game-iv/