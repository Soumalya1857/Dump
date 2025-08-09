class Solution {
private:
    long long getVal(vector<long long> &vec, long long index){
        if(index>=0 && index<vec.size()) return vec[index];
        return 0;
    }
public:
    long long gridGame(vector<vector<int>>& grid) {
        // only one down move you can take
        // 1 2 3 4 7 8 9
        // 6 3 6 7 8 9 1
        long long n = grid[0].size();
        vector<long long> prefix0(n, 0), prefix1(n,0);
        prefix0[0] = grid[0][0];
        prefix1[0] = grid[1][0];

        long long sum0 = grid[0][0], sum1 = grid[1][0];

        for(int i=1; i<n; i++){
            sum0 += grid[0][i];
            sum1 += grid[1][i];

            prefix0[i] = prefix0[i-1] + grid[0][i];
            prefix1[i] = prefix1[i-1] + grid[1][i]; 
        }

        long long mini = 1e17;

        for(int i=0; i<n; i++){
            // if robo1 takes down move here
            long long robo1Point = prefix0[i] + sum1 - getVal(prefix1, i-1); // might not be available

            long long robo2Point = max(sum0-prefix0[i], getVal(prefix1, i-1));
            mini = min(mini, robo2Point);
        }

        return mini;

    }
};

// https://leetcode.com/problems/grid-game/

// Optimization: can get rid of the prefix arrays and can determine on the fly

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(begin(grid[0]), end(grid[0]), 0LL), bottomSum = 0;
        long long ans = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); ++i) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return ans;
    }
};

// https://leetcode.com/problems/grid-game/
// https://leetcode.com/problems/grid-game/solutions/1486340/c-java-python-robot1-minimize-topsum-and-bottomsum-of-robot-2-picture-explained