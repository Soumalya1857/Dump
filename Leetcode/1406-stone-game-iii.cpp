class Solution {
public:
    int solve(vector<int> &stoneValue, int index, int currVal, int turn, vector<vector<int>> &dp){ // 0=> alice 1=> bob

        int size = stoneValue.size();

        if(index >= size){
            return currVal;
        }

        if(dp[index][turn] != 1e8){
            return dp[index][turn];
        }

        int value = turn == 0 ? INT_MIN: INT_MAX; // alice want to maximize
        int sum = 0;

        if(turn == 0){ // alice is the maxPlayer
            // can take upto 3 stones
            for(int i=index; i<min(size, index+3); i++){
                sum += stoneValue[i];
                value = max(value, solve(stoneValue, i+1,currVal+sum,1, dp));
            }
        } else if(turn == 1){ // bob is the minPlayer
            for(int i=index; i<min(size, index+3); i++){
                sum += stoneValue[i];
                value = min(value, solve(stoneValue, i+1,currVal-sum,0, dp));
            }
        }

        return dp[index][turn] = value;

    }
    string stoneGameIII(vector<int>& stoneValue) {

        vector<vector<int>> dp(stoneValue.size(), vector<int>(2,1e8));
        int val = solve(stoneValue, 0,0,0, dp);

        cout << "val: " << val << endl;

        if(val > 0) return "Alice";
        else if(val == 0) return "Tie";
        else return "Bob";
    }
};

// https://leetcode.com/problems/stone-game-iii/description/

// https://leetcode.com/problems/stone-game-iii/

// JAVA solution

class Solution {
    public String stoneGameIII(int[] arr) {
        int score = minimax(arr, 0, 1, new Integer[arr.length][2]);
        if (score > 0) return "Alice";
        if (score < 0) return "Bob";
        return "Tie";
    }
    int minimax(int[] arr, int i, int maxPlayer, Integer[][] dp) {
        if (i >= arr.length) return 0;
        if (dp[i][maxPlayer] != null) return dp[i][maxPlayer];
        int ans = maxPlayer == 1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        int score = 0;
        for (int j = i; j < Math.min(arr.length, i + 3); j++) {
            if (maxPlayer == 1) {
                score += arr[j];
                ans = Math.max(ans, score + minimax(arr, j + 1, 0, dp));
            } else {
                score -= arr[j];
                ans = Math.min(ans, score + minimax(arr, j + 1, 1, dp));
            }
        }
        return dp[i][maxPlayer] = ans;
    }
}


// https://leetcode.com/problems/stone-game-iii/solutions/564342/java-c-python-dynamic-programming/
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suffixSum(n+1, 0);
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];
        for (int i = n-1; i >= 0; i--) {
            dp[i] = stoneValue[i] + suffixSum[i+1] - dp[i+1];
            for (int k = i+1; k < i+3 && k < n; k++) {
                dp[i] = max(dp[i],  suffixSum[i]-dp[k+1]);
            }
        }
        if (dp[0]*2 == suffixSum[0])
            return "Tie";
        else if (dp[0]*2 > suffixSum[0])
            return "Alice";
        else
            return "Bob";
    }
};