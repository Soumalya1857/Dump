// https://leetcode.com/problems/ipo/
// https://www.youtube.com/watch?v=1IUzNJ6TPEM
class Solution {
    private:
        int solve(vector<int>& capitals, vector<int> &profits, int currCaptial, int index, int k, vector<vector<int>> &dp, int &maxi){
            maxi = max(maxi, currCaptial);

            if(index == capitals.size() || k == 0){
                return currCaptial;
            }

            if(dp[index][k] != -1){
                return dp[index][k];
            }

            if(currCaptial >= capitals[index]){
                return  dp[index][k] = max(solve(capitals, profits, currCaptial + profits[index], index+1, k-1, dp, maxi),
                        solve(capitals, profits, currCaptial, index+1, k, dp, maxi));
            }

            return dp[index][k] = solve(capitals, profits, currCaptial, index+1, k, dp, maxi);
        }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int maxi = INT_MIN;
        vector<vector<int>> dp(capital.size(), vector<int>(k+1, -1));
        solve(capital, profits, w, 0, k, dp, maxi);

        return maxi;

        // answer will be max of the whole dp array

    }
};


// this problem follows a generic and rare pattern though
// utilizing 2 heaps (in this case, one maxHeap and one minHeap)

// think about it
/*
    we certainly need such profits where the capital is within reach
    so if we need to go greedy then it's better to start from the lowest capital project

    add the profit to my totalProfit
*/