class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // can we utilize bfs anyhow
        int size = arr.size();
        vector<bool> isVisited(size, false);
        stack<int> q; // index

        q.push(start);

        while(!q.empty()){
            int currIndex = q.top();
            q.pop();

            if(arr[currIndex] == 0) return true;

            isVisited[currIndex] = true;

            int leftIndex = currIndex-arr[currIndex];
            if(leftIndex >= 0 && !isVisited[leftIndex]) q.push(leftIndex);

            int rightIndex = currIndex+arr[currIndex];
            if(rightIndex < size && !isVisited[rightIndex]) q.push(rightIndex);
        }

        return false;
    }

    // https://leetcode.com/problems/jump-game-iii/
};