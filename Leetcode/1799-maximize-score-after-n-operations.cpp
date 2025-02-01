class Solution {

private:
    int gcd(int x, int y){
        if(x < y) return gcd(y,x);

        if(y == 0) return x;
        else return gcd(y, x%y);
    }


    int solve(vector<int> &nums, unordered_map<int,bool> visited, int n, int operation, vector<int> &dp){
        if(operation > n){
            return 0;
        }

        // dp on operation will not work as the initial state of the array (visited) is also important
        // as it's changing as well
        // the DP should be over the array and not the operation number
        // that's where the bitMask comes in 
        //if(dp[operation] != -1) return dp[operation];

        int ans = -1;

        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                for(int j=i+1; j<nums.size(); j++){
                    if(!visited[j]){
                        visited[j] = true;

                        ans = max(ans, operation*gcd(nums[i], nums[j]) + solve(nums, visited, n, operation+1, dp));
                        
                        visited.erase(j);
                    }

                }

                visited.erase(i);
            }
            
        }

        return dp[operation] = ans;

    }

public:
    int maxScore(vector<int>& nums) {


        
        unordered_map<int,bool> visited;
        int n = nums.size()/2;
        int bitMask = (1<<nums.size()) - 1; // all 1's
        vector<int> dp(n+1,-1);
        return solve(nums, visited, n, 1, dp);
    }
};

// https://leetcode.com/problems/maximize-score-after-n-operations/
// https://leetcode.com/problems/maximize-score-after-n-operations/solutions/3523001/c-dp-recursive-memoization
// https://leetcode.com/problems/maximize-score-after-n-operations/solutions/3521639/recursion-boolean-array-mask-easy-to-understand-simple-code/




// submitted solution
class Solution {

private:
    int gcd(int x, int y){
        if(x < y) return gcd(y,x);

        if(y == 0) return x;
        else return gcd(y, x%y);
    }


    int solve(vector<int> &nums, int n, int operation, unordered_map<int,int> &dp, int mask){
        if(operation > n){
            return 0;
        }

        // dp on operation will not work as the initial state of the array (visited) is also important
        // as it's changing as well
        // the DP should be over the array and not the operation number
        // that's where the bitMask comes in 

        if(dp[mask]) return dp[mask];

        int ans = 0;

        // why bitwise xor works??
        // 

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if((mask & (1<<i)) && (mask & (1<<j))){
                    ans = max(ans, solve(nums, n, operation+1, dp, mask^(1<<i)^(1<<j)) + operation*gcd(nums[i], nums[j]));
                }
            }

            // if(!visited[i]){
            //     visited[i] = true;
            //     for(int j=i+1; j<nums.size(); j++){
            //         if(!visited[j]){
            //             visited[j] = true;

            //             ans = max(ans, operation*gcd(nums[i], nums[j]) + solve(nums, visited, n, operation+1, dp));
                        
            //             visited.erase(j);
            //         }

            //     }

            //     visited.erase(i);
            // }
            
        }

        return dp[mask] = ans;

    }

public:
    int maxScore(vector<int>& nums) {


        
        //unordered_map<int,bool> visited;
        int n = nums.size()/2;
        int bitMask = (1<<nums.size()) - 1; // all 1's
        unordered_map<int,int> dp;
        return solve(nums, n, 1, dp, bitMask);
    }
};

// https://leetcode.com/problems/maximize-score-after-n-operations/
// https://leetcode.com/problems/maximize-score-after-n-operations/solutions/3523001/c-dp-recursive-memoization










// ==============================================================================================================
// weird BFS solution

struct Position {
    int score;
    int ops;
    int index;
    int seen;
};

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int N = nums.size();
        int num_pairs = N * (N - 1) / 2;
        std::vector<std::array<int, 3>> gcds;
        gcds.reserve(num_pairs);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                gcds.push_back({gcd(nums[i], nums[j]), i, j});
            }
        }        
        std::sort(gcds.begin(), gcds.end(), std::greater());

        int ans = 0;
        int n = N / 2;
        // std::queue<std::array<int, 3>> q;
        std::queue<Position> q;
        q.push({.score=0, .ops=n, .index=0, .seen=0});
        while (!q.empty()) {
            // printf("q.size() = %u\n", q.size());
            Position& pos = q.front();
            int ops = pos.ops;
            int score = pos.score;
            int i = pos.index;
            int seen = pos.seen;
            q.pop();
            while (ops > 0 && i < num_pairs) {
                if (score + gcds[i][0] * ops * (ops + 1) / 2 <= ans) break;
                if (num_pairs - i < ops) break;
                std::array<int, 3>& g = gcds[i];
                if (seen & ((1 << g[1]) + (1 << g[2]))) {
                    ++i;
                    continue;
                }
                q.push({.score=score, .ops=ops, .index=++i, .seen=seen});
                score += ops-- * g[0];
                seen |= ((1 << g[1]) + (1 << g[2]));
                if (ops == 0) ans = max(ans, score);
            }        
        }
        return ans;

    }
};
