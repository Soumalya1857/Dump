class Solution {
public:
    int dp[1001] = {};
    // int maxJumps(vector<int>& arr, int d) {
    //     // // max to left 
    //     // // max to right
    //     int ans = INT_MIN;
    //     vector<int> maxLeft(arr.size(), -1), maxRight(arr.size(), -1);

    //     //TODO: determine max to left and max to right array
    //     // maxToright
    //     stack<int> s;
       

    //     for(int i=arr.size()-1; i>=0; i--){
    //         while(!s.empty()){
    //             int top = s.top();
                

    //             if(top > arr[i]){
    //                 maxRight[i] = top;
    //                 break;
    //             }
    //             s.pop();
    //         }
    //         s.push(arr[i]);
    //     }

    //     // maxToLeft
    //     for(int i=0; i<arr.size(); i++){
    //         while(!s.empty()){
    //             int top = s.top();
                

    //             if(top < arr[i]){
    //                 maxRight[i] = top;
    //                 break;
    //             }
    //             s.pop();
    //         }
    //         s.push(arr[i]);
    //     }
    //     // recursive approach in finding the maximum indices that you can visit
    //     for(int i=0; i<arr.size(); i++){
    //         ans = max(ans,  findMaxVisited(maxLeft, maxRight, d, i, 0));
    //     }

    //     return ans;
    // }

    // int findMaxVisited(vector<int> &maxLeft, vector<int> &maxRight, int d, int currIndex, int jumps){
    //     if(currIndex < 0 || currIndex >= maxLeft.size()) 
    //         return jumps;

    //     int ans = INT_MIN;
    //     // jump on left
    //     for(int i= currIndex-1; i>maxLeft[currIndex] && i>=0; i--)
    //         ans = max(ans, findMaxVisited(maxLeft, maxRight, d, i, jumps+1));

    //     // jump on right
    //     for(int i=currIndex+1; i<maxLeft.size() && i< maxRight[currIndex]; i++)
    //         ans = max(ans, findMaxVisited(maxLeft, maxRight, d, i, jumps+1));

        
    //     return ans;
    // }

    int dfs(vector<int>& arr, int i, int d, int res = 1) {
        if (dp[i]) return dp[i];
        for (auto j = i + 1; j <= min(i + d, (int)arr.size() - 1) && arr[j] < arr[i]; ++j)
            res = max(res, 1 + dfs(arr, j, d));
        for (auto j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j)
            res = max(res, 1 + dfs(arr, j, d));
        return dp[i] = res;
    }
    int maxJumps(vector<int>& arr, int d, int res = 1) {
        for (auto i = 0; i < arr.size(); ++i)
            res = max(res, dfs(arr, i, d));
        return res;
}
};

// https://leetcode.com/problems/jump-game-v/