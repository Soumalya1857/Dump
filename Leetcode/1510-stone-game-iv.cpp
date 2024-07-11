// https://leetcode.com/problems/stone-game-iv/description/
// Greedy won't work: think of the situation 13


// Greedy solution: Verdict: WA
class Solution {
public:
    bool winnerSquareGame(int n) {

        int val = n;
        int sqRoot = sqrt(n);
        if(sqRoot * sqRoot == n){
            return true; // alice won
        }

        int countOfSq = 0;

        while(val > 0){
            if(val < 4){
                countOfSq += val;
                //val = 0;
                break;
            }

            val = val - sqRoot*sqRoot; // 15 - 3*3
            countOfSq++;
            sqRoot--;
        }

        return countOfSq % 2 == 0 ? false : true;
    }
};

// =================================================================

// Solution should be of an DP base

class Solution {
private:
    bool solve(int currVal, vector<int> &dp){
       if(currVal == 0) return false; // bob wins

       if(dp[currVal] != -1) return dp[currVal];

        bool winner = false;

        for(int i=1; i*i <= currVal; i++){
            if(!solve(currVal-i*i, dp)){ // it's now from bob's perspective as we are taking i2 for alice
                                            // and pass it over to bob
                winner = true;
                break;
            }
        }

        return dp[currVal] = winner;

    }
public:
    bool winnerSquareGame(int n) {

       vector<int> dp(n+1, -1);
       return solve(n,dp);
    }
};

// https://www.youtube.com/watch?v=Gcg_a3r8FA0