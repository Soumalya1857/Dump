// class Solution {
// public:
// vector<vector<int>> dp;
//     int minOperations(vector<int>& nums, int x) {
//         dp.resize(nums.size(),vector<int>(nums.size(),-1));
//         int ans = solve(nums, dp,x, 0, nums.size()-1, 0);
//         return ans == INT_MAX ? -1 : ans;
//     }

//     int solve(vector<int> &nums, vector<vector<int>> &dp, int x, int front, int back, int operations){
//         if(x == 0) {
//             return operations;
//         }
//         if(front >= back) return INT_MAX;
//         if(x < 0) return INT_MAX;
//         if(dp[front][back]) return dp[front][back];

      

//         if(dp[front+1][back] == 0){
//             dp[front+1][back] = solve(nums, dp, x-nums[front], front+1, back, operations+1);
//         }
//         if(dp[front][back-1] == 0){
//             dp[front][back-1] = solve(nums, dp, x-nums[back], front, back-1, operations+1);
//         }
        
//         return dp[front][back] = min(dp[front+1][back], dp[front][back-1]);
        

//         return INT_MAX;
//     }
// };

// Classic Knapsack 0/1 problem
class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int s,int e,int x,int count=0){
        if(x==0)return count;
        if(s>e){
            return INT_MAX; 
        }
        if(dp[s][e]!=-1)return dp[s][e];
        int leftSide=solve(nums,s+1,e,x-nums[s] ,count+1);
        int rightSide=solve(nums,s,e-1,x-nums[e],count+1);
        
        return dp[s][e]=min(leftSide,rightSide);
        
    }
    int minOperations(vector<int>& nums, int x) {
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        int res=solve(nums,0,nums.size()-1,x);
        return res==INT_MAX?-1:res;
    }
}; 

// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/


// accepted solution
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
    //     int sum = 0;
    //     for(int i : nums) sum += i;
    //     if(sum == x) return nums.size();
    //     int target = sum - x;
    //     int start = 1, end = nums.size();

    //    for(int slidingWindowSize = nums.size()-2; slidingWindowSize >= 1; slidingWindowSize--){
    //        if(isPossible(nums, target, slidingWindowSize)){
    //            return nums.size() - slidingWindowSize;
    //        }
    //    }

    //    return -1;


    // map with memorization prefix sum

    unordered_map<int, int> map; // val, index
    int sum = nums[0], ans = INT_MIN;
    vector<int> prefix(nums.size(),0);
    prefix[0] = nums[0];

    for(int i=1; i<nums.size(); i++){
        sum += nums[i];
        prefix[i] = prefix[i-1] + nums[i];
    }

    if(prefix[prefix.size()-1] == x) return nums.size();

    int target = sum - x;

    for(int i=0; i<prefix.size(); i++){
        int find = prefix[i] - target;
        if(find == 0) {ans = max(ans, i+1);}
        else if(map[find] || map[find] == -1){
            ans = max(ans, i- (map[find] == -1 ? 0 : map[find]));

            // as everything is positive...no need to continue
            // continue;
        }

        map[prefix[i]] = i==0 ? -1 : i; //  map entry with 0 doesn't make sense
    }

    return ans == INT_MIN ? -1 : nums.size() - ans;
        


    }

    bool isPossible(vector<int>& nums, int target, int slidingWindowSize){
        int sum = 0;
        for(int i=0; i<slidingWindowSize; i++){
            sum += nums[i];
        }

        if(sum == target) return true;

        for(int i=slidingWindowSize; i<nums.size(); i++){
            sum = sum + nums[i] - nums[i-slidingWindowSize];
            if(sum == target) return true;
        }

        return false;
    }
};



// variable sliding window approach still there to learn