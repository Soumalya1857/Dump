
// trick is to not use the N-1 scenario
// as it lead to O(N} complexity
// just assume that we have taken that step whenever
//N%2 != 0 or N%3!=0

class Solution {
public:

    int solve(int N, unordered_map<int, int> &dp){

        if(N == 0) return 0;
        if(N < 0) return INT_MAX;

        int first = INT_MAX, second = INT_MAX, third = INT_MAX;


            if(dp[N/2]){
                second = N%2 + 1 + dp[N/2]; // imp
            } else second = 1 + N%2 +solve(N/2, dp);



            if(dp[N/3]){
                third = 1 + N%3 + dp[N/3]; // imp
            } else third = 1 + N%3 + solve(N/3, dp);

        return dp[N] =  min(second, third);

    }
    int minDays(int n) {
        unordered_map<int, int> dp;
        return solve(n,dp)-1;

    }
};

// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/solutions/794351/java-o-log-2n-beats-100-time-with-explanation



class Solution {
    private HashMap<Integer,Integer> mp = new HashMap<>();
    public int minDays(int n) {
        if(n <= 2)
            return n;
        if(mp.containsKey(n))
            return mp.get(n);

        mp.put(n, 1 + Math.min(n % 2 + minDays(n/2), n % 3 + minDays(n/3)));
        return mp.get(n);
    }
}